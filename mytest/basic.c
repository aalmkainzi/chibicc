_Nameprefix A = "A__";

_Apply _Nameprefix A
{
    int i = 10;
}


int main()
{
    return A::i;
};