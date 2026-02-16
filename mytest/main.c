_Nameprefix A = "A__";
_Nameprefix A::B = "A__B__";
_Nameprefix A = "A__";
_Nameprefix A::B = "A__B__";

_Apply _Nameprefix A
{
    _Apply _Nameprefix B
    {
        int foo();
    }
}

_Apply _Nameprefix A::B
{
    
}

int main()
{
    return A__B__foo();
}