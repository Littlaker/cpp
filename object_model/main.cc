struct A
{
    int a_;
    virtual void a() {}
};

struct B : public A
{
    int b_;
    virtual void a() override {}
    virtual void b() {}
};

struct C : public A
{
    int c_;
    virtual void a() override {}
    virtual void c() {}
};

struct D : public B, public C
{
    int d_;
    virtual void a() override {};
    virtual void b() override {};
    virtual void c() override {};
    virtual void d() {};
};

struct E : virtual public B, virtual public C
{
    int e_;
    virtual void a() override {};
    virtual void b() override {};
    virtual void c() override {};
    virtual void e() {};
};

// gcc 9.0 前
// g++ -fdump-class-hierarchy -c main.cc

// gcc 9.0 后
// $ g++ -fdump-lang-class -c main.cc

// cat main.cc.001l.class  | c++filt -n > main.class
int main()
{
    return 0;
}