#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>

#include "opt_node.h"

using namespace std;
using namespace hvs;

//mutex mtx_write

namespace hvs{
std::vector<Node> SelectNode::buf_delay;
std::mutex SelectNode::mtx;

vector<Node> SelectNode::getNode(){
    return buf_delay;
}

void SelectNode::setNode(Node &mynode){
    buf_delay.push_back(mynode);
}

void SelectNode::erase_v(){
    buf_delay.clear();
}

void SelectNode::mutex_lock(){
    mtx.lock();
}

void SelectNode::mutex_unlock(){
    mtx.unlock();
}

}//namespace hvs
