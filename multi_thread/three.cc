
//=========================================

#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>

#include "opt_node.h"

using namespace std;
using namespace hvs;


void *write_buf_delay(void *arg){
    //cout<<"thread: write_buf_delay"<<endl;
    Node Beijing, Shanghai, Guangzhou, Changsha, Jinan;
    SelectNode anode;

    while(1){
        cout<<"wirte lock"<<endl;
        anode.mutex_lock();
        anode.erase_v();

        Beijing.location = "Beijing";
        Beijing.ip_addr = "bbbb";
        Beijing.port = "9090";
        anode.setNode(Beijing);
        

        Shanghai.location = "Shanghai";
        Shanghai.ip_addr = "sssss";
        Shanghai.port = "9091";
        anode.setNode(Shanghai);

        Guangzhou.location = "Beijing";
        Guangzhou.ip_addr = "GGGG";
        Guangzhou.port = "9090";
        anode.setNode(Guangzhou);


        Changsha.location = "Shanghai";
        Changsha.ip_addr = "CCCC";
        Changsha.port = "9091";
        anode.setNode(Changsha);


        Jinan.location = "Beijing";
        Jinan.ip_addr = "JJJJJ";
        Jinan.port = "9090";
        anode.setNode(Jinan);

        cout << "sleep 5" << endl;
        sleep(5);
        cout<<"wirte unlock"<<endl;
        anode.mutex_unlock();

        cout << "write sleep 10" << endl;
        sleep(10);
        
    }

}



void *_read_buf(void *arg){
    //cout << "thread: _read_buf" << endl;
    
    vector<Node> mynode;
    SelectNode onenode;

    while(1){
        sleep(1);
        cout << "read start" << endl;
        
        onenode.mutex_lock();
        mynode = onenode.getNode();
        onenode.mutex_unlock();
        cout << "read end" << endl;

        cout << mynode.at(0).location << endl;
        cout << mynode.at(1).location << endl;

    }
}



int main(){


    pthread_t tid_writer, tid_reader;
    int ret;
    if(pthread_create(&tid_writer, NULL, write_buf_delay, NULL) == -1){
        return 0;
    }
    if(pthread_create(&tid_reader, NULL, _read_buf, NULL) == -1){
        return 0;
    }


    if(pthread_join(tid_writer, NULL) == -1){
        puts("fail to recollect tid");
        exit(1);
    }
    if(pthread_join(tid_reader, NULL) == -1){
        puts("fail to recollect tid");
        exit(1);
    }
    cout << "end" << endl;
    return 0;
}
