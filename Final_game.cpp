#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int DRAGON=0,NINJIA=1,ICEMAN=2,LION=3,WOLF=4;//���ó����������ں궨�壬����ĳЩ�����·���ʹ�ã�����switch����С�
const int now_order[2][5]={{2,3,4,1,0},{3,0,1,2,4}};//�����ܲ��ĳ�������
const char* Color[2]={"red","blue"};//�����ܲ�����
const char* Character[5]={"dragon","ninja","iceman","lion","wolf"};//ʿ������
const char* Weapon[3]={"sword","bomb","arrow"};//��������
int need[5],order[2],number[2],_attack[5],worriors_temp[2],now_time,city_sum,total[2];
int arrow_attack,loyalty_minus;

bool head_num[2],game_over,last_color[2];
/* sword������ */
class sword
{
private:
    int force;//������
public:
    sword(int x):force(x) {}//���캯��
    void used() {force=(int)(force*0.8);}//swordÿ����һ��ս��(�����������������Ƿ���)���ͻ��ۣ���������Ϊ����ս��ǰ��80% (ȥβȡ��)��
    bool is_deserted() {return (force==0);}//sword��������Ϊ0ʱ��sword����ʿ������
    int get_force() {return force;}//���ع�����ֵ
};
/* arrow������ ע�⣺�������ڵ���ʿ����ͬʱ�ż��ѶԷ������� */
class arrow
{
private:
    int used_times;//ʹ�ô���
    int force;//������
public:
    arrow(int x,int y):used_times(x),force(y) {}//���캯��
    void used() {used_times--;}//ʹ��һ��
    bool is_deserted() {return (used_times==0);}//����������
    int get_force() {return force;}//���ع�����
    int get_used_time() {return used_times;}//����ʹ�ô���
};
/* ��ʿ�� */
class worriors
{
public:
    worriors(int,int,int);//���캯��
    ~worriors()
    {
        if (_sword!=NULL) delete _sword;
        if (_arrow!=NULL) delete _arrow;
    }
    void get_hp(int a) {hp+=a;}
    virtual void happy(int) {}//�麯��,����dragon
    virtual void change_morale(int) {}//�麯��,����dragon
    virtual bool will_escape() {return false;}//�麯��,����lion
    virtual void minus_loyalty() {}//�麯��,����lion
    friend class city;//��Ԫ��city
protected:
    int type;//ʿ������
    int id;//���
    int hp;
    int color;//������ɫ
    int attack;
    sword* _sword;
    arrow* _arrow;
    bool has_bomb;
};
class dragon: public worriors
{
private:
    double morale;//ʿ��
public:
    dragon(int _color,int _id,int _type):worriors(_color,_id,_type)
    {
        morale=(double)total[_color]/(double)need[0];//dragon���С�ʿ����������ԣ��Ǹ�����������ֵΪ����������˾�ʣ������Ԫ������������dragon���������Ԫ������
        printf("Its morale is %.2lf\n",morale);
    }
    void happy(int _id)
    {
        if (morale>0.8)
            printf("%.3d:40 %s dragon %d yelled in city %d\n",now_time,Color[color],id,_id);//dragon ��һ����������������ս�������������û��ս��������ʿ��ֵ����0.8���ͻỶ����
    }
    void change_morale(int a) {morale+=((a==1)?0.2:-0.2);}//dragonÿȡ��һ��ս����ʤ��(���˱�ɱ��)��ʿ���ͻ�����0.2��ÿ����һ��δ�ܻ�ʤ��ս����ʿ��ֵ�ͻ����0.2��ʿ�����������ڻ���֮ǰ��
};
class lion: public worriors
{
private:
    int loyalty;//lion �С��ҳ϶ȡ��������
public:
    lion(int _color,int _id,int _type):worriors(_color,_id,_type)
    {
        loyalty=total[_color];//���ʼֵ����������֮����˾�ʣ������Ԫ����Ŀ��
        cout<<"Its loyalty is "<<loyalty<<endl;
    }
    bool will_escape() {return (loyalty<=0);}//�ҳ϶Ƚ���0��0���£����lion����ս��,��Զ��ʧ��
    void minus_loyalty() {loyalty-=loyalty_minus;}//ÿ����һ��δ��ɱ�����˵�ս�����ҳ϶Ⱦͽ���K
};
/* ������ */
class city
{
private:
    int id;
    int color;
    int hp;
    int last_beat_win;
    int just_beat_win;
public:
    worriors* data[2];
    ~city()
    {
        for (int i=0;i<=1;i++)
            if (data[i]!=NULL)
                delete data[i];
    }
    void creat(int);
    void input_hp() {hp+=10;};
    void output_hp();
    void beat_win(int,int,int);
    void beat();
    void draw(int);
    void go(city*,int);
    bool reach_headquater(int);
    void print_last_go();
    void escape(int);
    void use_bomb();
    void tell_weapon(int);
    void shoot_arrow(city*,int);
    int get_attack(int);
    int get_just_beat_win() {return just_beat_win;}
    void bang(int);
} citys[22];

worriors::worriors(int _color,int _id,int _type)
{
    cout<<now_time<<":00 "/*����ط�������*/Color[_color]<<%s %d born\n",now_time,Color[_color],Character[_type],_id);//��ÿ�����㣬��ÿ��Сʱ�ĵ�0�֣� ˫����˾��и���һ����ʿ������
    total[_color]-=need[_type];
    id=_id;
    color=_color;
    type=_type;
    hp=need[_type];
    attack=_attack[_type];
    _sword=NULL;
    has_bomb=false;
    _arrow=NULL;
    switch(_type)
    {
    case DRAGON:case ICEMAN:
        switch (id%3)
        {
        case 0:
            if ((int)(attack*0.2)!=0)
                _sword=new sword(int(attack*0.2));
            break;
        case 1:
            has_bomb=true;
            break;
        default:
            _arrow=new arrow(3,arrow_attack);
        }
        break;
    case NINJIA:
        switch(id%3)
        {
        case 0:
            if ((int)(attack*0.2)!=0)
                _sword=new sword(int(attack*0.2));
            has_bomb=true;
            break;
        case 1:
            has_bomb=true;
            _arrow=new arrow(3,arrow_attack);
            break;
        default:
            _arrow=new arrow(3,arrow_attack);
            if ((int)(attack*0.2)!=0)
                _sword=new sword(int(attack*0.2));
        }
        break;
    default:;
    }
}
void city::creat(int _id)
{
    last_beat_win=just_beat_win=color=-1;
    id=_id;
    hp=0;
    data[0]=data[1]=NULL;
}
void city::beat_win(int _color,int left_hp,int y)
{
    if (data[_color]->type==WOLF)
    {
        if (data[_color]->_sword==NULL && data[1-_color]->_sword!=NULL)
            data[_color]->_sword=new sword(data[1-_color]->_sword->get_force());
        if (!data[_color]->has_bomb && data[1-_color]->has_bomb)
            data[_color]->has_bomb=true;
        if (data[_color]->_arrow==NULL && data[1-_color]->_arrow!=NULL)
            data[_color]->_arrow=new arrow(data[1-_color]->_arrow->get_used_time(),data[1-_color]->_arrow->get_force());
    }
    delete data[1-_color];
    data[1-_color]=NULL;
    if (y==1)
    {
        data[_color]->change_morale(1);
        data[_color]->happy(id);
    }
    data[_color]->hp+=left_hp;
    printf("%.3d:40 %s %s %d earned %d elements for his headquarter\n",now_time,
        Color[_color],Character[data[_color]->type],data[_color]->id,hp);
    worriors_temp[_color]+=hp;
    hp=0;
    just_beat_win=_color;
    if (color!=_color && last_beat_win==_color)
    {
        color=_color;
        printf("%.3d:40 %s flag raised in city %d\n",now_time,Color[_color],id);
    }
    last_beat_win=_color;
}
void city::output_hp()
{
    int turn=-1;
    if (data[0]!=NULL && data[1]==NULL) turn=0;
    if (data[1]!=NULL && data[0]==NULL) turn=1;
    if (turn!=-1)
    {
        printf("%.3d:30 %s %s %d earned %d elements for his headquarter\n",now_time,Color[turn],Character[data[turn]->type],data[turn]->id,hp);
        total[turn]+=hp;
        hp=0;
    }
}
void city::beat()
{
    int turn=1,left_hp=0,add_attack;
    just_beat_win=-1;
    if (data[0]==NULL)
    {
        if (data[1]!=NULL && data[1]->hp==0)
        {
            delete data[1];
            data[1]=NULL;
        }
        return;
    }
    if (data[1]==NULL)
    {
        if (data[0]->hp==0)
        {
            delete data[0];
            data[0]=NULL;
        }
        return;
    }
    if (color==0 || (color==-1 && id%2==1)) turn=0;
    if (data[turn]->hp==0 && data[1-turn]->hp==0)
    {
        delete data[0];
        delete data[1];
        data[0]=data[1]=NULL;
        return;
    }
    if (data[turn]->hp==0)
    {
        beat_win(1-turn,0,0);
        return;
    }
    if (data[1-turn]->hp==0)
    {
        beat_win(turn,0,1);
        return;
    }
    printf("%.3d:40 %s %s %d ",now_time,Color[turn],Character[data[turn]->type],data[turn]->id);
    printf("attacked %s %s %d in city %d with %d elements and force %d\n",Color[1-turn],Character[data[1-turn]->type],data[1-turn]->id,id,data[turn]->hp,data[turn]->attack);
    if (data[1-turn]->type==LION)
        left_hp=data[1-turn]->hp;
    add_attack=get_attack(turn);
    data[1-turn]->hp-=data[turn]->attack+add_attack;
    if (data[1-turn]->hp<=0)
    {
        printf("%.3d:40 %s %s %d was killed in city %d\n",now_time,Color[data[1-turn]->color],Character[data[1-turn]->type],data[1-turn]->id,id);
        beat_win(turn,left_hp,1);
        return;
    }
    if (data[1-turn]->type!=NINJIA)
    {
        add_attack=get_attack(1-turn);
        printf("%.3d:40 %s %s %d fought back against %s %s %d in city %d\n",now_time,Color[1-turn],
            Character[data[1-turn]->type],data[1-turn]->id,Color[turn],Character[data[turn]->type],data[turn]->id,id);
        if (data[turn]->type==LION)
            left_hp=data[turn]->hp;
        else left_hp=0;
        data[turn]->hp-=data[1-turn]->attack/2+add_attack;
        if (data[turn]->hp<=0)
        {
            printf("%.3d:40 %s %s %d was killed in city %d\n",now_time,Color[data[turn]->color],Character[data[turn]->type],
                data[turn]->id,id);
            beat_win(1-turn,left_hp,0);
            return;
        }
    }
    draw(turn);
}
int city::get_attack(int _color)
{
    int add_attack=0;
    if (data[_color]->_sword!=NULL)
    {
        add_attack=data[_color]->_sword->get_force();
        data[_color]->_sword->used();
        if (data[_color]->_sword->is_deserted())
        {
            delete data[_color]->_sword;
            data[_color]->_sword=NULL;
        }
    }
    return add_attack;
}
void city::draw(int turn)
{
    data[0]->minus_loyalty();
    data[1]->minus_loyalty();
    data[turn]->change_morale(-1);
    data[turn]->happy(id);
    last_beat_win=-1;
}
void city::go(city* next,int _color)
{
    data[_color]=next->data[_color];
    if (data[_color]!=NULL && data[_color]->type==ICEMAN)
    {
        if ((_color==0 && id%2==0) || (_color==1 && (city_sum-id)%2==1))
        {
            data[_color]->hp-=9;
            if (data[_color]->hp<=0) data[_color]->hp=1;
            data[_color]->attack+=20;
        }
    }
}
bool city::reach_headquater(int _color)
{
    if (!last_color[_color]) return false;
    printf("%.3d:10 %s %s %d reached %s headquarter with %d elements and force %d\n",now_time,
        Color[_color],Character[data[_color]->type],data[_color]->id,Color[1-_color],data[_color]->hp,data[_color]->attack);
    if (head_num[_color]) return true;
    head_num[_color]=true;
    return false;
}
void city::print_last_go()
{
    for (int i=0;i<=1;i++)
        if (data[i]!=NULL)
            printf("%.3d:10 %s %s %d marched to city %d with %d elements and force %d\n",now_time,
            Color[i],Character[data[i]->type],data[i]->id,id,data[i]->hp,data[i]->attack);
}
void city::escape(int i)
{
    if (data[i]!=NULL && data[i]->will_escape())
    {
        printf("%.3d:05 %s lion %d ran away\n",now_time,Color[i],data[i]->id);
        delete data[i];
        data[i]=NULL;
    }
}
void city::use_bomb()
{
    int turn=1;
    if (data[0]==NULL || data[1]==NULL || data[0]->hp==0 || data[1]->hp==0)
        return;
    if (color==0 || (color==-1 && id%2==1)) turn=0;
    int add_force=0;
    if (data[turn]->_sword!=NULL)
        add_force=data[turn]->_sword->get_force();
    if (data[1-turn]->hp<=data[turn]->attack+add_force)
    {
        if (data[1-turn]->has_bomb)
            bang(1-turn);
        return;
    }
    if (data[1-turn]->type==NINJIA)
        return;
    add_force=0;
    if (data[1-turn]->_sword!=NULL)
        add_force=data[1-turn]->_sword->get_force();
    if (data[turn]->hp<=data[1-turn]->attack/2+add_force && data[turn]->has_bomb)
        bang(turn);
}
void city::bang(int turn)
{
    printf("%.3d:38 %s %s %d used a bomb and killed %s %s %d\n",now_time,Color[turn],
        Character[data[turn]->type],data[turn]->id,Color[1-turn],Character[data[1-turn]->type],data[1-turn]->id);
    delete data[0];
    delete data[1];
    data[0]=data[1]=NULL;
}
void city::tell_weapon(int _color)
{
    bool e=false;
    if (data[_color]==NULL) return;
    printf("%.3d:55 %s %s %d has ",now_time,Color[_color],Character[data[_color]->type],data[_color]->id);
    if (data[_color]->_arrow!=NULL)
    {
        printf("arrow(%d)",data[_color]->_arrow->get_used_time());
        e=true;
    }
    if (data[_color]->has_bomb)
    {
        if (e) printf(",");
        printf("bomb");
        e=true;
    }
    if (data[_color]->_sword!=NULL)
    {
        if (e) printf(",");
        printf("sword(%d)",data[_color]->_sword->get_force());
        e=true;
    }
    if (!e) printf("no weapon");
    printf("\n");
}
void city::shoot_arrow(city* next,int _color)
{
    if (data[_color]==NULL) return;
    if (data[_color]->_arrow!=NULL && next->data[1-_color]!=NULL)
    {
        printf("%.3d:35 %s %s %d shot",now_time,Color[_color],Character[data[_color]->type],data[_color]->id);
        next->data[1-_color]->hp-=data[_color]->_arrow->get_force();
        data[_color]->_arrow->used();
        if (data[_color]->_arrow->is_deserted())
        {
            delete data[_color]->_arrow;
            data[_color]->_arrow=NULL;
        }
        if (next->data[1-_color]->hp<=0)
        {
            next->data[1-_color]->hp=0;
            printf(" and killed %s %s %d",Color[1-_color],Character[next->data[1-_color]->type],next->data[1-_color]->id);
        }
        printf("\n");
    }
}
void creat()
{
    for (int i=0;i<=1;i++)
    {
        if (total[i]>=need[now_order[i][order[i]]])
        {
            worriors* temp;
            number[i]++;
            switch (now_order[i][order[i]])
            {
            case 0:
                temp=new dragon(i,number[i],now_order[i][order[i]]);
                break;
            case 3:
                temp=new lion(i,number[i],now_order[i][order[i]]);
                break;
            default:
                temp=new worriors(i,number[i],now_order[i][order[i]]);
            }
            citys[((i==0)?0:(city_sum+1))].data[i]=temp;
            order[i]=(order[i]+1)%5;
        }
    }
}
void go_ahead()
{
    last_color[0]=last_color[1]=false;
    if (citys[city_sum].data[0]!=NULL)
    {
        citys[city_sum+1].go(&citys[city_sum],0);
        last_color[0]=true;
    }
    for (int i=city_sum;i>=1;i--)
        citys[i].go(&citys[i-1],0);
    if (citys[1].data[1]!=NULL)
    {
        citys[0].go(&citys[1],1);
        last_color[1]=true;
    }
    for (int i=1;i<=city_sum;i++)
        citys[i].go(&citys[i+1],1);
    citys[0].data[0]=citys[city_sum+1].data[1]=NULL;
    if (citys[0].reach_headquater(1))
    {
        printf("%.3d:10 red headquarter was taken\n",now_time);
        game_over=true;
    }
    for (int i=1;i<=city_sum;i++)
        citys[i].print_last_go();
    if (citys[city_sum+1].reach_headquater(0))
    {
        printf("%.3d:10 blue headquarter was taken\n",now_time);
        game_over=true;
    }
}
void pride()
{
    for (int i=1;i<=city_sum;i++)
    {
        if (total[1]<8) break;
        if (citys[i].get_just_beat_win()==1)
        {
            citys[i].data[1]->get_hp(8);
            total[1]-=8;
        }
    }
    for (int i=city_sum;i>=1;i--)
    {
        if (total[0]<8) break;
        if (citys[i].get_just_beat_win()==0)
        {
            citys[i].data[0]->get_hp(8);
            total[0]-=8;
        }
    }
    for (int i=0;i<=1;i++)
    {
        total[i]+=worriors_temp[i];
        worriors_temp[i]=0;
    }
}
int main()
{
    int times;
    cin >> times;
    int input,total_time,already_time;
    for (int t=1;t<=times;t++)
    {
        cin >> input >> city_sum >> arrow_attack >> loyalty_minus >> total_time;
        total[0]=total[1]=input;
        already_time=0;
        game_over=false;
        now_time=-1;
        number[0]=number[1]=0;
        order[0]=order[1]=0;
        head_num[0]=head_num[1]=false;
        for (int i=0;i<=4;i++)
            cin >> need[i];
        for (int i=0;i<=4;i++)
            cin >> _attack[i];
        printf("Case %d:\n",t);
        for (int i=0;i<=city_sum+1;i++)
            citys[i].creat(i);
        while (1)
        {
            now_time++;
            creat();
            already_time+=5;
            if (already_time>total_time) break;
            citys[0].escape(0);
            for (int i=1;i<=city_sum;i++)
                for (int j=0;j<=1;j++)
                    citys[i].escape(j);
            citys[city_sum+1].escape(1);
            already_time+=5;
            if (already_time>total_time) break;
            go_ahead();
            for (int i=1;i<=city_sum;i++)
                citys[i].input_hp();
            already_time+=20;
            if (game_over || already_time>total_time) break;
            for (int i=1;i<=city_sum;i++)
                citys[i].output_hp();
            already_time+=5;
            if (already_time>total_time) break;
            citys[1].shoot_arrow(&citys[2],0);
            for (int i=2;i<=city_sum-1;i++)
            {
                citys[i].shoot_arrow(&citys[i+1],0);
                citys[i].shoot_arrow(&citys[i-1],1);
            }
            citys[city_sum].shoot_arrow(&citys[city_sum-1],1);
            already_time+=3;
            if (already_time>total_time) break;
            for (int i=1;i<=city_sum;i++)
                citys[i].use_bomb();
            already_time+=2;
            if (already_time>total_time) break;
            for (int i=1;i<=city_sum;i++)
                citys[i].beat();
            pride();
            already_time+=10;
            if (already_time>total_time) break;
            for (int i=0;i<=1;i++)
                printf("%.3d:50 %d elements in %s headquarter\n",now_time,total[i],Color[i]);
            already_time+=5;
            if (already_time>total_time) break;
            for (int j=0;j<=1;j++)
                for (int i=0;i<=city_sum+1;i++)
                    citys[i].tell_weapon(j);
            already_time+=5;
            if (already_time>total_time) break;
        }
    }
    return 0;
}