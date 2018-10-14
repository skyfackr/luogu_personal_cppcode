#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define syp system("pause")
#define syc system("cls")
#define SentenceNumber 17  
using namespace std;
const int inf=1e9+7;
struct node
{
    int x,y;
};
class llang//Sinization by.skyfackr 
{
	private:
		int language=0;//1:chinese 2:english
		int l1,l2;
		bool Is_Language_Initializated=false;
		inline bool Is_Language_pointed()
		{
			if (language==0&&l1==0&&l2==0) return false;
			else return true;
		}
		inline bool Compare_language_function()
		{
			if (language!=l1||l1!=l2||language!=l2) return true;
			else return false;
		}
		//sentence
		std::map<string,string> sentence;
		struct Sentence_Saver1
		{
			
			
			string In_Program_Name[SentenceNumber];
			string English_Sentence[SentenceNumber];
			string Chinese_Sentence[SentenceNumber];
		}Sentence_Saver;
		inline string Sentence_found(string s)
		{
			return sentence[s];
		}
		void LangERR_fixed()
		{
			if (!Is_Language_Initializated)
			{
				syc;
				cout<<"ERR_langguage_service_start_failed"<<endl;
				syp;
				exit(0);
			}
			if (!Is_Language_pointed())
			{
				syc;
				cout<<"......well,you win"<<endl;
				syp;
				exit(0);
			}
			if (Compare_language_function())
			{
				syc;
				cout<<"Junk hacker...."<<endl;
				syp;
				exit(0);
			}
			return;
		}
		
		
		
		void Sentence_Initialization_Centre()
		{
			syc;
			
			while (!Is_Language_pointed())
			{
				syc;
				cout<<"Language selected failed.Please try again"<<endl;
				cin>>language;
				l1=l2=language;
			}
			syc;
			if (Compare_language_function())
			{
				syc;
				cout<<"Junk hacker...."<<endl;
				syp;
				exit(0);
			}
			if (l1==1) cout<<"语言服务初始化……"<<endl;
			else cout<<"Sentence service initializating... ..."<<endl; 
			int i=0;
			ifstream name,en,cn;
			name.open("/Language/Sentence_Name",ios::in);
			en.open("/Language/EN/Sentence",ios::in);
			cn.open("/Language/CN/Sentence",ios::in);
			while (i<=SentenceNumber-1&&(!name.eof()))
			{
				name>>Sentence_Saver.In_Program_Name[i];
				cout<<Sentence_Saver.In_Program_Name[i]<<endl;
				i++;
			}
		
			if (i==SentenceNumber-1&&name.eof())
			{
				syc;
				cout<<"ERR_Sentence_No_Readall"<<endl;
				exit(0);
			}
			if (i<SentenceNumber-1)
			{
				syc;
				cout<<"ERR_Sentence_Name_Toofew"<<endl;
				exit(0);
			}
		
			i=0;
			while (i<=SentenceNumber-1&&(!cn.eof()))
			{
				cn>>Sentence_Saver.Chinese_Sentence[i];
				i++;
			}
			
			if (i==SentenceNumber-1&&cn.eof())
			{
				syc;
				cout<<"ERR_Sentence_No_Readall"<<endl;
				exit(0);
			}
			if (i<SentenceNumber-1)
			{
				syc;
				cout<<"ERR_Sentence_cn_Toofew"<<endl;
				exit(0);
			}
		
			i=0;
			while (i<=SentenceNumber-1&&(!en.eof()))
			{
				en>>Sentence_Saver.English_Sentence[i];
				i++;
			}
			
			if (i==SentenceNumber-1&&en.eof())
			{
				syc;
				cout<<"ERR_Sentence_No_Readall"<<endl;
				exit(0);
			}
			if (i<SentenceNumber-1)
			{
				syc;
				cout<<"ERR_Sentence_en_Toofew"<<endl;
				exit(0);
			}
		
			name.close();
			cn.close();
			en.close();
			if (language==1)
			{
				system("title 贪吃蛇 by ZZX");
				for (int j=0;j<=SentenceNumber-1;j++)
				{
					sentence[Sentence_Saver.In_Program_Name[j]]=Sentence_Saver.Chinese_Sentence[j];
				}
			}
			else
			{
				system("title Snake by ZZX");
				for (int j=0;j<=SentenceNumber-1;j++)
				{
					sentence[Sentence_Saver.In_Program_Name[j]]=Sentence_Saver.English_Sentence[j];
				}
			}
			syc;
			Is_Language_Initializated=true;
			return;
		}
		inline void language_get()
		{
			l1=l2=language;
		}
	public:
		string findword(string s)
		{
			LangERR_fixed();
			string ss=Sentence_found(s);
			return ss;
		}
		void languagehold()
		{
			syc;
			system("title Snake(choose language)");
			int x;
			cout<<"选择你的语言"<<endl<<"Select your language"<<endl;
			cout<<"1,简体中文"<<endl<<"2,English"<<endl;
			cin>>x;
			while (x!=1&&x!=2)
			{
				cout<<"exm???????"<<endl<<"选择你的语言"<<endl<<"Select your language"<<endl;
				cout<<"1,简体中文"<<endl<<"2,English"<<endl;
				cin>>x;
			} 
			language=x;
			language_get();
			Sentence_Initialization_Centre();
			LangERR_fixed();
		}
}; 
llang lang;
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
    syc;
    cout<<lang.findword("lose")<<endl;
    cout<<lang.findword("losepoint")<<(int)dq.size()<<endl;
}
void Input()
{
    cout<<lang.findword("sizein")<<endl;
    cin>>m;
    cout<<lang.findword("speedin")<<endl;
    cin>>Difficulty;
    while (Difficulty<=0)
    {
    	cout<<endl;
    	cout<<lang.findword("errspeed")<<endl;
    	cout<<lang.findword("speedin")<<endl;
    	cin>>Difficulty;
    }
    bool xxx=true;
    while (Difficulty<=10&&xxx)
    {
    	cout<<endl<<lang.findword("hellspeed")<<endl;
    	char xxxx;
    	cin>>xxxx;
    	switch (xxxx)
    	{
    		case 'y':
    			xxx=false;
				continue;
    		case 'n':
    			cout<<lang.findword("speedin")<<endl;
    			cin>>Difficulty;
    			continue;
    	}
    	cout<<lang.findword("hellspeedinerr")<<endl;
    }
}
void Init()
{
    syc;
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
    syc;
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
        cout<<lang.findword("ltime")<<(ShowTime+0.0)/1000.0<<lang.findword("ltimes")<<endl;
        if(ShowTime<=0)
        {
            Dead();
            syp;
            exit(0);
        }
    }
    cout<<endl<<"Snake made by Zhao Zixuan"<<endl<<"Sinization powered by skyfackr"<<endl;
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
            syp;
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
    
	cout<<lang.findword("selectmode")<<endl;
    cout<<lang.findword("mode1")<<endl;
    cout<<lang.findword("mode2")<<endl;
    cout<<lang.findword("mode3")<<endl;
    cout<<lang.findword("mode4")<<endl;
    int tmpm;
    cin>>tmpm;
    if(tmpm==1)
    {
        Mode=1;
    }
    else if(tmpm==2)
    {
        Mode=2;
        cout<<endl<<lang.findword("timein")<<endl;
        cin>>TLimit;
        TLimit*=1000;
    }
    else if(tmpm==3)
    {
        Mode=3;
        cout<<endl<<lang.findword("objin")<<endl;
        cin>>NumbO;
    }
    else if(tmpm==4)
    {
    	lang.languagehold();
    	Choose_Mode();
    }
    else
    {
        cout<<lang.findword("illin")<<endl;
        exit(0);
    }
    syc;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
//	system("color 9E");
    lang.languagehold();
    Choose_Mode();
    Input();
    Init();
    OriTime=clock();
    Play();
    return 0;
}
