#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

const int maxx = 3;
const string listt[] = {"vietnam","trungquoc","nhatban","aicap","angiang","bariavungtau","bacgiang","baccan","baclieu","bacninh","bentre","binhdinh","binhduong","binhphuong","binhthuan","camau","cantho","caobang","danang","daklak","daknong","dienbien","dongnai","dongthap","gialai","hagiang","hanam","hanoi","hatinh","haiduong","haiphong","haugiang","hoabinh","hungyen","khanhhoa","kiengiang","kontum","laichau","lamdong","langson","laocai","longan","namdinh","nghean","ninhbinh","ninhthuan","phutho","phuyen","quangbinh","quangnam","quangngai","quangtri","quangninh","soctrang","sonla","tayninh","thaibinh","thanhhoa","thuathienhue","tiengiang","thanhphohochiminh","travinh","tuyenquang","vinhlong","vinhphuc","yenbai","anh","argentina","armenia","ao","arapxeut","ando","bahrain","balan","bangladesh","bacmacedonia","belarus","bi","bolivia","bodaonha","bobiennga","braxin","brunei","bulgaria","cameroon","campuchia","lao","thailan","indonexia","singapore","timorleste","canada","chile","colombia","cactieuvuongquocarapthongnhat","congo","costarica","croatia","danmach","ecuador","duc","my","mongco","estonia","elsalvador","ethiopia","gabon","gambia","ghana","guatemala","guinea","haiti","halan","honduras","hungary","hylap","iceland","iran","iraq","ireland","israel","jamaica","jordan","kazakhstan","kuwait","kyrgyzstan","latvia","liban","liberia","litva","luxembourg","maroc","mexico","monaco","montenegro","mozambique","myanmar","namphi","nauy","nepal","newzealand","lienbangnga","nigeria","oman","pakistan","palestine","panama","paraguay","peru","phap","phanlan","philippines","romania","qatar","senegal","serbia","conghoasec","slovakia","srilanka","sudan","syria","tajikistan","taybannha","thonhiky","thuydien","thuysi","trieutien","turkmenistan","ukraina","uruguay","uzbekistan","australia","vatican","venezuela","yemen","italia","zambia"};

const int countlistt = sizeof(listt) / sizeof(string);

string ScretWord();
void RenderGame(string GuessWord, int cnt);
char MyChoose();
bool Contain(string ScretWord, char word);
int TotalScore();
string Update(string ScretWord, string GuessWord, char word);
int Score();

int main ()
{
    system("Color 0A");
    srand(time(0));
    int totalscore = 0;

    string s = ScretWord();
    char w;
    string g = string(s.size(),'-');
    cout << "TOTAL NUMBER OF BLANKS " << s.size() << endl;
    int cnt = maxx;
    do
    {
        RenderGame(g, cnt);
        int p = Score();
        cout << "Congratulations! You received: " << p << " points in this turn if you TRUE!" << endl;
        w = MyChoose();
        if (Contain(s, w))
        {
            g = Update(s, g, w);
            totalscore += p;
        }
        else cnt--;
        cout << "Current score you have: " << totalscore << endl;
        cout <<"" << endl;

    } while (cnt > 0 && g != s);
    cout << "Chance remain: " << cnt << endl;
    if (cnt == 0) cout << ". GAME OVER!" << endl << "KEY: " << s << endl;
    else if (cnt == 1)
    {
        cout << ". CONGRATULATIONS! YOU LUCK! \n KEY: " << s << endl;

        cout << "TOTAL SCORE: " << totalscore << endl;
    }
    else
    {
        cout << ". GOOD JOB MAN! YOU'RE NOT HUMAN @@" << endl << "KEY: " << s << endl;
        cout << "TOTAL SCORE: " << totalscore << endl;
    }
    return 0;
}

string ScretWord()
{

    int random = rand() % countlistt;
    return listt[random];
}

void RenderGame(string GuessWord, int cnt)
{
    cout << GuessWord << endl;
    cout << "Chance remain: " << cnt << endl;
}

char MyChoose()
{
    char input;
    cout << "Your choose: ";
    cin >> input;
    return input;
}

bool Contain(string ScretWord, char word)
{
    int l = ScretWord.find(word);
    if (l >= 0 && l < ScretWord.size()) return true;
    return false;
}

string Update(string ScretWord, string GuessWord, char word)
{
    for (int i = ScretWord.size() - 1; i >= 0; i--)
    {
        if (word == ScretWord[i])
        {
            GuessWord[i] = word;
        }
    }
    return GuessWord;
}

int Score()
{
    int x = rand() % (10-0+1) + 0;
    return x;
}






