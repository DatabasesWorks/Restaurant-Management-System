#ifndef USER_H
#define USER_H
#include<QHash>
#include<QString>
#include<QCryptographicHash>
#include"score.h"
using namespace std;
class user{

    long long NO;                    //�˻����ֻ���

    QString password;          //����

    friend class chef;         //����Ԫ���ڷ���
    friend class waiter;
    friend class manager;
    friend class admin;
    friend class customer;

    static QHash<long long,user *>map;//�þ�̬��Ա��ϣ��洢�����û�

public:

    user(long long no,QString pw):
        NO(no),
        password(pw)
    {}

    static QHash<long long,user *> &get_map();

    static void _register(long long get_NO,QString get_pw);  //ע��

    virtual QString get_password();

    virtual long long get_NO();

};

//�����������Ч��

inline QHash<long long,user *> & user::get_map(){
    return map;
}

inline void user::_register(long long get_NO,QString get_pw){
    map[get_NO]=new user(get_NO,get_pw);
}

inline QString user::get_password(){
    return password;
}

inline long long user::get_NO(){
    return NO;
}

#endif
