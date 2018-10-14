#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
const int inf=1e9+7;
struct node
{
    int x,y;
};
class lang//”Ô—‘∫∫ªØ£∫skyfackr 
{
	private:
		int language=0;//1:chinese 2:english
		bool Is_Language_Initializated=false;
		std::map<string,string> sentence;
		void Sentence_Initialization_Centre()
		{
			
		}
} 
int NumbO;
int OriTime;
int TLimit;
int Mode;//1->Original 2->Time 3->Object
char mp[200][200];
int m;
int Difficulty;
deque<node> dq;
int dir=1;//1->  2^  3<-   4V
int dy[5]={0,1,0,-1,0};
int dx[5]={0,0,1,0,-1};


bool used[200][200];
int ddx[4]={0,0,1,-1};
int ddy[4]={1,-1,0,0};
void Dfs(int x,int y)
{
    used[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+ddx[i];
        int ny=y+ddy[i];
        if(nx<1 || ny<1 || nx>m || ny>m) continue;
        if(!used[nx][ny] && mp[nx][ny]!='&') Dfs(nx,ny);
    }
}
bool DFS_Check()
{
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans+=used[i][j];
        }
    }
    return ans==m*m;
}


void Dead()
{
    system("Cls");
    cout<<"Game Over!"<<endl;
    cout<<"Your point is "<<(int)dq.size()<<endl;
}
void Input()
{
    cout<<"Input the size!"<<endl;
    cin>>m;
    cout<<"Input the Speed(ms)!"<<endl;
    cin>>Difficulty;
}
void Init()
{
    system("Cls");
    srand((unsigned int)time(NULL));
    for(int i=0;i<=m+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        mp[i][j]=' ';
    }
    for(int i=0;i<=m+1;i++)
    {
        mp[i][m+1]=mp[i][0]=mp[m][i]=mp[0][m+1]='&';
    }
    mp[2][2]='*';
    
    if(Mode==3)
    for(int i=0;i<NumbO;i++)
    {
        while(1)
        {
            int ox=rand()%m+1;
            int oy=rand()%m+1;
            Dfs(ox,oy);
            if(DFS_Check() && (ox!=2 && oy!=2))
            {
                mp[ox][oy]='&';
                break;
            }
        }
    }
    
    int ChuX=rand()%(m/2)+3;
    int ChuY=rand()%(m/2)+3;
    node Chu;
    Chu.x=ChuX,Chu.y=ChuY;
    dq.push_back(Chu);
    mp[ChuX][ChuY]='@';
}
void Show()
{
    system("Cls");
    for(int i=0;i<=m+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        cout<<mp[i][j];
        cout<<endl;
    }
    if(Mode==2)
    {
        int CurTime=clock();
        int ShowTime=TLimit-(CurTime-OriTime);
        cout<<"Time left:"<<(ShowTime+0.0)/1000.0<<"s"<<endl;
        if(ShowTime<=0)
        {
            Dead();
            system("pause");
            exit(0);
        }
    }
    cout<<endl<<"Snake made by Zhao Zixuan"<<endl;
}
bool Check(int x,int y)
{
    return mp[x][y]!='@' && mp[x][y]!='&';
}
void Play()
{
    while(1)
    {
        Show();
        
        int tclock=clock();
        
        if(_kbhit())
        {
        	char ch=_getch();
        	if(ch==119) dir=4;
        	if(ch==97) dir=3;
        	if(ch==115) dir=2;
        	if(ch==100) dir=1;
        }
        
        int x=dq.front().x;
        int y=dq.front().y;
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(nx==-1) nx=m-1;
        if(ny==0) ny=m;
        if(nx==m) nx=0;
        if(ny==m+1) ny=1;
        if(mp[nx][ny]=='&' || mp[nx][ny]=='@')
        {
            Dead();
            system("pause");
            exit(0);
        }
        node fa;
        fa.x=nx;
        fa.y=ny;
        dq.push_front(fa);
        if(mp[nx][ny]=='*')
        {
            mp[nx][ny]=' ';
            int fx=rand()%m+1;
            int fy=rand()%m+1;
            if(fx==-1) fx=m-1;
            if(fy==0) fy=m;
            if(fx==m) fx=0;
            if(fy==m+1) fy=1;
            while(!Check(fx,fy))
            {
                fx=rand()%m+1;
                fy=rand()%m+1;
                if(fx==-1) fx=m-1;
                if(fy==0) fy=m;
                if(fx==m) fx=0;
                if(fy==m+1) fy=1;
            }
            
            mp[fx][fy]='*';
        }
        else
        {
            mp[dq.back().x][dq.back().y]=' ';
            dq.pop_back();
        }
        mp[nx][ny]='@';
        Sleep(Difficulty);
    }
}
void Choose_Mode()
{
    cout<<"Please choose your mode"<<endl;
    cout<<"1:Original mode"<<endl;
    cout<<"2:Time limit mode"<<endl;
    cout<<"3:Object mode"<<endl;
    int tmpm;
    cin>>tmpm;
    if(tmpm==1)
    {
        Mode=1;
    }
    else if(tmpm==2)
    {
        Mode=2;
        cout<<endl<<"Input the time limit(s)"<<endl;
        cin>>TLimit;
        TLimit*=1000;
    }
    else if(tmpm==3)
    {
        Mode=3;
        cout<<endl<<"Input the number of objects"<<endl;
        cin>>NumbO;
    }
    else
    {
        cout<<"Illegal input!"<<endl;
        exit(0);
    }
    system("Cls");
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
//	system("color 9E");
    system("title Snake by ZZX");
    Choose_Mode();
    Input();
    Init();
    OriTime=clock();
    Play();
    return 0;
}
