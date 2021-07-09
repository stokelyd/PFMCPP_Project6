/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) {}   //1
    int value;  //2
    std::string name;   //3
};

struct TFunction                               //4
{
    const T* compare( const T& a, const T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float var1 { 0.f }, var2 { 0.f };

    float smoothAndMultiply(const float& updatedValue)      //12
    {
        std::cout << "U's var1 value: " << var1 << std::endl;
        var1 = updatedValue;
        std::cout << "U's var1 updated value: " << var1 << std::endl;
        while( std::abs(var2 - var1) > 0.001f )
        {
            var2 += 0.1f;
        }
        std::cout << "U's var2 updated value: " << var2 << std::endl;
        return var2 * var1;
    }
};

struct UFunction
{
    static float smoothAndMultiply( U& that, const float& updatedValue )        //10
    {
        std::cout << "U's var1 value: " << that.var1 << std::endl;
        that.var1 = updatedValue;
        std::cout << "U's var1 updated value: " << that.var1 << std::endl;
        while( std::abs(that.var2 - that.var1) > 0.001f )
        {
            /*
             write something that makes the distance between that->var2 and that->var1 get smaller
            */
            that.var2 += 0.1f;
        }
        std::cout << "U's var2 updated value: " << that.var2 << std::endl;
        return that.var2 * that.var1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T alpha( 6, "alpha" );                                             //6
    T beta( 2, "beta" );                                             //6
    
    TFunction f;                                            //7
    const auto* smaller = f.compare( alpha, beta );                              //8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    
    
    U gamma;
    float updatedValue = 5.f;
    std::cout << "[static func] gamma's multiplied values: " << UFunction::smoothAndMultiply( gamma, updatedValue ) << std::endl;                  //11
    
    U delta;
    std::cout << "[member func] delta's multiplied values: " << delta.smoothAndMultiply( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
