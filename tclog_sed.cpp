// tclog_sed.cpp: определяет точку входа для приложения.
//

#include <iostream>
//#include <fstream>
//#include <sstream>
#include <regex>
#include <vector>

using namespace std;
/*
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;

string readFileIntoString(const string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}
*/

static const vector < pair < const regex, const char * >> substitutions{
    {regex("[0-2]0[0-2][0-9]-[0-1][0-9]-[0-3][0-9]"), "YYYY-MM-DD"},
    {regex("[0-3][0-9].[0-1][0-9].[0-2]0[0-9][0-9]"), "DD.MM.YYYY"},
    {regex("[0-2][0-9]:[0-5][0-9]:[0-5][0-9]"), "hh:mm:ss"},
    {regex("[0-2][0-9]:[0-5][0-9]"), "hh:mm"},
    {regex("\\\\"), "/"},
    {regex("/work/[0-9a-f]+"), "/WORK_DIR"},
    {regex("custom_script[0-9]+"), "CUSTOM_SCRIPT"}
    };


int main()
{
    string row;
    while (getline(cin, row))
    {
        for each (auto const s in substitutions)
            row = regex_replace(row, s.first, s.second);
        cout << row << endl;
    }
    return EXIT_SUCCESS;
}
