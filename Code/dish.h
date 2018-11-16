#ifndef DISH_H
#define DISH_H
#include"score.h"
#include"chef.h"
#include<QString>
#include<QHash>

using namespace std;
//��Ʒ����
class dishtype{

    QString name;

    int price;

    score dishscore;       //���ౣ�������������

    int status;            //0:δ�� ,1��������2��������3�����ϲˣ�4�����ϲ�

    QString type;

    static QHash<QString,dishtype *>dishtype_map;     //�þ�̬��Ա��ϣ�������в�

    chef * this_chef;

public:

    dishtype(QString get_name,int get_price,QString get_type=""):
        type(get_type),
        name(get_name),
        price(get_price),
        status(0),
        this_chef(NULL)
    {}

    dishtype(QString get_name,int get_price,QString get_type,int amount,int total):
        type(get_type),
        name(get_name),
        price(get_price),
        dishscore(amount,total),
        this_chef(NULL)
    {}  //�������ڴ����ݿ����

    static QHash<QString,dishtype *> &get_map();

    static void add(QString n,int p,QString type,int amount,int total);

    static void add(QString n,int p,QString type="");

    void change_price(int pr);

    QString get_name();

    QString get_type();

    int get_price();

    int & get_status();

    score & get_score();

    chef *&get_chef();

    void ordered();   //��ˣ��ı�status

    void cooking();   //������ 

    void cooked();    //������

    void served();    //���ϲ�

    void pay();       //�ѽ���

};

//�����������Ч��

inline void dishtype::served(){
    status=4;
}

inline void dishtype::pay(){
    status=0;
    this_chef=NULL;
}

inline QHash<QString,dishtype *> & dishtype::get_map(){
    return dishtype_map;
}

inline void dishtype::add(QString n,int p,QString type){
    dishtype_map[n]=new dishtype(n,p,type);
}

inline void dishtype::add(QString n,int p,QString type,int amount,int total){
    dishtype_map[n]=new dishtype(n,p,type,amount,total);
}

inline void dishtype::change_price(int pr){
    price=pr;
}

inline QString dishtype::get_name(){
    return name;
}

inline QString dishtype::get_type(){
    return type;
}

inline int dishtype::get_price(){
    return price;
}

inline int & dishtype::get_status(){
    return status;
}

inline score & dishtype::get_score(){
    return dishscore;
}

inline void dishtype::ordered(){
    status=1;
}

inline void dishtype::cooking(){
    status=2;
}

inline chef *& dishtype::get_chef(){
    return this_chef;
}

#endif
