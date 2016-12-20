#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

struct variable{
    string name;
    int value;
};

struct funct{
    char funct_name;
    vector<string> commands;
};

stack<char> s;

char get_function_name(string line);
char get_variable_declaration(string line, vector<variable> &v);
bool update_varabile(string line, vector<variable> & v);
bool read_code(string file_name, vector<funct> &my_functions, vector<variable> & v);
void callStack(funct f, vector<funct> &my_function,vector<variable> &v);

int main()
{
    vector<funct> my_functions;
    vector<variable> v;

    string file_name;

    cout << "What is the name of the code file: ";
    getline(cin,file_name);
    cout << file_name << endl;

    if(read_code(file_name,my_functions, v))   //This means the code was read from file
    {
        /*** Functionality to write. When the read_code function finishes it's going to be
        time to actually run the code and use the call stack. Add that functionality here.
        Don't forget you have to write out the call stack as it changes and the values
        of the variables at the end of execution. ***/

        funct firstFunction;

        for (int i = 0; i < my_functions.size();i++){
            if (my_functions.at(i).funct_name == 'm'){
                firstFunction = my_functions.at(i);
                break;
            }
        }
        s.push(firstFunction.funct_name);
        callStack(firstFunction,my_functions,v);
        cout<<"Final Values of all variables are: "<<endl;
        for (int i = 0; i < v.size();i++){
            cout << v.at(i).name + "="<< v.at(i).value<< endl;
        }

    }


    return 0;
}

/*** FUNCTIONS TO WRITE ***/

//This is one way to do it.
//Objective: read in a file and determine
bool read_code(string file_name, vector<funct> &my_functions, vector<variable> & v)
{
    vector<string> code;
    string s;
    std::size_t found;
    bool flag;
    funct new_function;

    ifstream in;
    in.open(file_name.c_str());
    if(in.is_open())
    {
        //read in file line by line and put it into a vector called code
        while(in.peek()!=EOF)
        {
            getline(in,s);
            code.push_back(s);
        }
        in.clear();
        in.close();

        //read through each line of the code, determine if it's a variable or function (definition or call)
        //here it makes reference to functions (listed following this one) which will actually decompose the line
        //for information
        for(int i=0;i<code.size();i++)
        {
            //check if it's a variable declaration
            found = code[i].find("var");
            if(found!=std::string::npos)    //its a variable declaration
                get_variable_declaration(code[i], v);

            //check if it's a function. it'll go in the list of functions
            found = code[i].find("funct");
            if (found!=std::string::npos)   //that means it's a function
            {
                new_function.funct_name=get_function_name(code[i]);
                new_function.commands.clear();
                i+=2;   //skip over the open curly brace
                flag=false;
                while(!flag)
                {
                    found = code[i].find("}");
                    if(found==std::string::npos)
                    {
                        new_function.commands.push_back(code[i]);
                        i++;
                    }
                    else
                    {
                        my_functions.push_back(new_function);
                        flag=true;
                    }
                }
            }
        }

        return true;
    }
    else
    {
        cout << "Cannot locate this file" << endl;
        return false;
    }
}


char get_function_name(string line)
{
    //we have a string that has the keyword call or funct in it.
    //so go throught the sring, when you encounter the keyword "funct", skip the space character that follows and return the the next three characters
    //if you encounter the keyword "call", do the same thing as well.

    for(int i = 0; i < line.length();i++){
            if ((i < line.length() - 5)&& (line.substr(i,i+5) == "funct")){
                return line.at(i+6);
            }
            if ((i < line.length()-4)&&(line.substr(i,i+4)=="call")){
                return line.at(i+5);
            }

    }
    return 'm';
    //This function will take in a line of code
    //that is confirmed to have a function declaration
    //or call to a function.
    //it will return the name of the function
}

char get_variable_declaration(string line, vector<variable> &v)
{
    //read through the line, if you find the word "var", skip the space character and then create a struct object with the name of the variable
    //which comes right after the space and with a value that is found right after the assignment operator which is found right after the variable.
    //then add the struct instance into the vector v.
    variable var1;
    for(int i = 0; i < line.length()-3; i++){
        if(line.substr(i,i+3)=="var"){
                var1.name = line.at(i+4);

                var1.value = line.at(i+6);
                v.push_back(var1);
                break;

        }
    }
    return var1.name.at(0);

    //This function will take in a line of code
    //that is confirmed to have a variable declaration
    //it will add the variable to the list of
    //vectors
}

bool update_varabile(string line, vector<variable> & v)
{
    //read throught the string, then if you find a an assignment character,
    //then read the value that comes immediately after the assignment character and save it.
    //Now iterate through the vector
    char replacementValue;
    char replacedVariable;
    bool varr = true;
    char separator;
    int toBeAdded;
    for(int i = 0; i < line.length();i++){
        if(line.at(i) == '='){

            replacedVariable = line.at(i-1);
            if(line.at(i+1) != line.at(i-1)){
               replacementValue = line.at(i+1);
               varr = false;
            }
            else{

                separator = line.at(i+2);
                toBeAdded = line.at(i+3);
            }
            break;
        }
    }
    for(int i = 0; i < v.size(); i++){

        if(v.at(i).name.at(0) == replacedVariable){

            if(varr){

                if(separator == '+'){

                    v.at(i).value = v.at(i).value + toBeAdded;
                }
                else if(separator == '-'){
                    v.at(i).value = v.at(i).value - toBeAdded;
                }
                else if(separator == '*'){
                    v.at(i).value = v.at(i).value*toBeAdded;
                }
                else if(separator == '/'){
                    v.at(i).value = v.at(i).value/toBeAdded;
                }
                else{
                    v.at(i).value = v.at(i).value%toBeAdded;
                }
            }
            else{
                v.at(i).value = replacementValue;
            }

            return true;

        }

    }
    return false;
    //This function will take in a line of code
    //that is confirmed to have a assignment statement
    //for a variable and will update the variable value
    //returns true if the variable is there, false if not
}
void callStack(funct f, vector<funct> &my_function,vector<variable> &v)
{
    /**iterate through the vector above and try to find the function called 'm'.accumulate
        then push that to the stack to start things off.

        examine the stack(in this case m) and go through all the commands of the function at the top.
        if you find a function name in the commands of the function you are examining then find that function in your vector my_functions
        and then push that to your stack and start examining its contents in the same way(can see a loop here).
        if you encounter a variable name in the command, then print out the value of the variable from your vector v separated by whitespace.

        if you encounter a closing brace, then pop stuff of the stack and continue examining the top element(best way to do this would be recursion)
        **/
    //Base case
    if(s.empty())
    {
        return;
    }
    else
    {
        char current = s.top();
        funct currentF;
        for(int i = 0; i < my_function.size();i++){
            if(my_function.at(i).funct_name == current){
                currentF = my_function.at(i);
                break;
            }

        }
        //go through the commands of the function and push function name to stack if a function is called or
        //print out the value of a variable if a variable is used or pop it from the stack if the end of the function is reached.

        for(int i = 0;  i < currentF.commands.size();i++){
            // if the string in commands is a function call, then push to stack and go through its contents.
            for (int j = 0; j < my_function.size();j++){
                if((currentF.commands.at(i).substr(0,4) == "call") && (currentF.commands.at(i)[5] == my_function.at(j).funct_name)){
                    s.push(my_function.at(j).funct_name);
                    callStack(my_function.at(j),my_function,v);
                }
            }
            for(int j = 0; j < v.size(); j++){
                if ((currentF.commands.at(i)[0] == v.at(j).name.at(0)) &&(currentF.commands.at(i)[1] == '=')){
                    update_varabile(currentF.commands.at(i),v);

                }
            }

        }
        s.pop();
        return;

    }


}
