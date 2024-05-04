#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

#define SIZE 19

char maze[SIZE][SIZE];
int maze_order[SIZE][SIZE]={0};
int offset[8][2] = {{1,1}, {1,0}, {0,1}, {1,-1}, {-1,0}, {0,-1},{-1,-1}, {-1,1}};
int offset_cost[8]={14,10,10,14,10,10,14,14};

int startx, starty, finx, finy;

struct Node {
    int x, y;
    int parentx, parenty;
    
    int costa;
    int costb;
    int costt;
    Node(int x, int y, int parentx, int parenty, int costa, int costb, int costt) 
    : x(x), y(y), parentx(parentx), parenty(parenty), costa(costa), costb(costb), costt(costt) {}
};

struct cmp {
    bool operator()(Node a, Node b) {
        return a.costt > b.costt;
    }
};
priority_queue<Node, vector<Node>, cmp> pq;
vector<Node> order_reverse;
stack<Node> order;
void LoadMap(const char* filename);
void ReadMap();
void StartPos();
void FinishPos();


void Route(int x, int y, int b);
void OrderRoute();
void OrderMap();
void ReadOrder();

int main(void) 
{

    LoadMap("Maze.txt");
    StartPos();
    FinishPos();
    ReadMap();
    Route(startx, starty, 0);
    OrderRoute();
    OrderMap();
    ReadMap();
    system("pause"); // cmd 자동 종료 방지
}

void StartPos()
{
    int x,y;
    ReadMap();
    cout<<"시작 좌표를 입력해주세요."<<endl;
    cin>>x;
    cin>>y;
    while(maze[x][y]!='0')
    {
        cout<<"시작 좌표를 입력해주세요."<<endl;       
        cin>>x;
        cin>>y;
    }
    startx=x;
    starty=y;
    maze[startx][starty]='x';
    cout<<endl;
}

void FinishPos()
{
    int x,y;
    ReadMap();
    cout<<"도착 좌표를 입력해주세요."<<endl;
    cin>>x;
    cin>>y;
    while(maze[x][y]!='0')
    {
        cout<<"도착 좌표를 입력해주세요."<<endl;       
        cin>>x;
        cin>>y;
    }
    finx=x;
    finy=y;
    maze[finx][finy]='y';
    cout<<endl;
}

void Route(int x, int y, int b) 
{
    int parentx=0, parenty=0;
    int childx=0, childy=0;
    int parent_costb = b;

    int costa=0, costb=0, costt=0;

    parentx=x;
    parenty=y;
    if(x==finx && y == finy) return;
    else
    {
        for (int i = 0; i < 8; i++) 
        {
            childx = parentx + offset[i][0];
            childy = parenty + offset[i][1];
            
            if (childx >= 0 && childx <= 18 && childy >= 0 && childy <= 18 ) // Map의 범위 안에 있는지 확인
            {
                if(maze[childx][childy]!='x' && maze[childx][childy]!='1' && maze[childx][childy]!='2') // 시작 위치, 벽, 이미 방문한 경우는 제외
                {
                    costa = 10*(abs(childx - finx) + abs(childy - finy)); 
                    costb = parent_costb + offset_cost[i];
                    costt = costa+costb;
                    pq.push(Node(childx, childy, parentx, parenty, costa, costb, costt));

                }

            }
        }
        if(pq.empty()) // 우선순위 큐에서 빼낼 노드(경로)가 없다 -> 도착지로 가는 경로가 없다.
        {
            cout<<"No Route"<<endl;
            return;
        }


        Node temp = pq.top();
        pq.pop();
        while(maze[temp.x][temp.y]=='2') // 우선순위 큐에서 동일한 좌표로 가는 노드(경로)를 중복 선택 방지 위함
        {
            temp=pq.top();
            pq.pop();
        }

        order_reverse.push_back(temp);

        if(maze[temp.x][temp.y]=='0')
            maze[temp.x][temp.y] = '2';

        Route(temp.x,temp.y, temp.costb);  
    }
}


void LoadMap(const char* filename) 
{
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) 
        {
            char value;
            file >> value;
            maze[i][j] = value;
        }
    }

    file.close();
}

void ReadMap() 
{
    cout<<"Map"<<endl;
    cout<<setw(3)<<left<<"";
    for(int i=0; i< SIZE; i++)
        cout<<setw(4)<<left<<i;
    cout<<endl;


    for (int i = 0; i < SIZE; i++) 
    {
        cout<<setw(3)<<left<<i;
        for (int j = 0; j < SIZE; j++) 
        {
            //cout<<setw(3)<<left<<maze[i][j];
            if(maze[i][j] == '1') cout<<setw(5)<<left<<"■";
            else if(maze[i][j]=='0') cout<<setw(5)<<left<<"□"; 
            else if(maze[i][j]=='x') cout<<setw(5)<<left<<"♣";
            else if(maze[i][j]=='y') cout<<setw(5)<<left<<"♥";
            else if(maze[i][j]=='3') cout<<setw(4)<<left<<maze_order[i][j];
            else
                if(maze[i][j]=='2') cout<<setw(5)<<left<<"□"; 
        }
        cout<<endl;
    }
    cout<<endl;

}

void OrderRoute()
{
    int i=order_reverse.size()-1;
    while(i>=0)
    {

        order.push(order_reverse[i]);
        
        int tempx = order_reverse[i].parentx;
        int tempy = order_reverse[i].parenty;
        if(maze[tempx][tempy]=='2')
            maze[tempx][tempy]='3';
        i--;
        while(order_reverse[i].x != tempx || order_reverse[i].y != tempy)
        {
            i--;
            if(i<0) break;
        }
    }
}

void OrderMap()
{
    int j=1;
    while(!order.empty())
    {
        int x = order.top().x;
        int y = order.top().y;

        maze_order[x][y]=j++;
        order.pop();
    }
}


void ReadOrder()
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            cout<<setw(3)<<maze_order[i][j];
        }
        cout<<endl;
    }
}

