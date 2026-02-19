
_Nameprefix A = "A__";
_Nameprefix A::B = "A__B__";
_Nameprefix C = "C__";


_Apply _Nameprefix A::B
{
    _Capture _Nameprefix C
    {
        int C__baz() { return 100; };
        
        _Apply _Nameprefix A
        {
            int qux()
            {
                return 1;
            }
        }
        
        _Apply _Nameprefix A::B
        {
            int qux()
            {
                return 2;
            }
        }
    }
    int foo() { return 10; }
}

_Apply _Nameprefix A
{
    int my_cool_var = 69;
    _Apply _Nameprefix B
    {
        int bar()
        {
            return 3;
        }
    }
}

_Apply _Nameprefix A
{
    struct SS
    {
        int i;
    };
    typedef int i32;
    
    enum Flags2
    {
        A2,B2=69,C2
    }
}

_Capture _Nameprefix A
{
    typedef short A__i16;
    
    enum A__Flags
    {
        A,B,C
    }
    
}

int main()
{
    enum A::Flags2 a = A::B2;
    return a;
}