
namespace Thrylos
{
   _declspec(dllimport) void Print(); 
}


int main(int argc, char* argv[])
{
    Thrylos::Print();
    return 0;
}
