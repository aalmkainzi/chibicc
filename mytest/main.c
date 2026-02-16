_Nameprefix A = "A__";
_Nameprefix A::B = "A__B__";
_Nameprefix A = "A__";
_Nameprefix A::B = "A__B___";

_Apply _Nameprefix A
{
    _Apply _Nameprefix B
    {
        
    }
}

_Apply _Nameprefix A::B
{
    
}

int main()
{
    return 0;
}