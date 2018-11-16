#ifndef TABLE_H
#define TABLE_H
#include<QVector>
#include<QHash>
#include<QString>
#include"waiter.h"
class table{

    int tableNO;                           //����

    waiter *this_waiter;                   //�洢Ϊ��������ķ���Աָ��

    static QHash<int,table *>table_map;    //�þ�̬��Ա��ϣ��洢��������

    QHash<QString,int>dish_map;            //�ù�ϣ��洢��������˼�����

    int status;                            //0�����У�1���й˿ͣ�2���з���Ա

public:

    table(int get_NO):
        tableNO(get_NO),
        status(0),
        this_waiter(NULL)
    {}

    static QHash<int,table *> &get_map();

    static void add(int get_NO);             //��������

    void add_dish(QString name,int amount);  //���

    QHash<QString,int> &get_dish_map();

    int get_tableNO();

    int get_status();

    waiter *&get_waiter();

    void get_chosen();        //��ѡ��

    void get_service();       //����Ա��ʼ����

    void pay();               //����
};

//�����������Ч��

inline QHash<int,table *> & table::get_map(){
    return table_map;
}

inline void table::add(int get_NO){
    table_map[get_NO]=new table(get_NO);
}

inline void table::add_dish(QString name,int amount){
    dish_map[name]=amount;
}

inline QHash<QString,int> & table::get_dish_map(){
    return dish_map;
}

inline int table::get_tableNO(){
    return tableNO;
}

inline int table::get_status(){
    return status;
}

inline waiter *& table::get_waiter(){
    return this_waiter;
}

inline void table::get_chosen(){
    status=1;
}

inline void table::get_service(){
    status=2;
}
#endif
