#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
public:
    // 禁止拷贝和构造
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton&) = delete;

    Singleton(Singleton&& ) = delete;
    Singleton& operator=(Singleton&& ) = delete;

    // 静态函数返回静态对象的引用
    static Singleton& getInstance();
    
    // 其他公有函数
    void printInfo() const;

private:
    // 禁止外部调用构造函数创建对象
    Singleton();

    //
    ~Singleton();
};


#endif //!SINGLETON_H   
