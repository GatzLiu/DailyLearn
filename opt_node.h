#ifndef _OPTNODE_H_
#define _OPTNODE_H_

#include <iostream>
#include <vector>
#include <mutex>


namespace hvs{


struct Node{
	std::string location;
	std::string ip_addr;
	std::string port;
};



class SelectNode{
public:
    SelectNode(){
        //读取配置文件，作为初值
    }
    ~SelectNode(){}

    std::vector<Node> getNode();
    void setNode(Node &mynode);

    void erase_v();

    void mutex_lock(); //因为mtx是私有，只能定义成员函数来操作
    void mutex_unlock();

private:
   static std::vector<Node> buf_delay;   //static因为多个SelectNode对象需要共享同一个 缓冲区
   static std::mutex mtx;  //static因为多个SelectNode对象需要使用同一个(共享)mtx
};


}//namespace hvs
#endif