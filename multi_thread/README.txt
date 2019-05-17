tmp.sh是编译命令

在头文件中只声明变量 或者 函数，不要进行定义，这是因为定义会实际分配内存，若多个.cc文件包含此.h，会出现multiple define的问题（这是因为每个目标文件的符号表都包含该变量，造成multiple define）

私有静态成员变量在.h 中仅仅是声明，需要定义，但建议在.h对应的.cc文件中定义，否则多个文件引用此.h 会出现multiple define的问题  
https://blog.csdn.net/mrailence/article/details/52388027

之所以定义私有静态成员函数，是多个类对象需要共享一个变量；

SelectNode类
    std::vector<Node> getNode();
    void setNode(Node &mynode);
    void erase_v();
	三个函数是为了操作静态私有变量buf_delay
	
	void mutex_lock(); 
    void mutex_unlock();
	两个函数是为了操作静态私有变量mtx
	
因此SelectNode类的目的是：为了多个线程引用该类，进行数据共享的（实例化该类对象，进行缓冲区(buf_write)和互斥量(mtx)共享的）