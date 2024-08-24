#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

char Path[255] = "";
string Command = "";

vector<string> split(const string& s, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void Loop() {
    while (true) {
        Command = "";
        getline(cin, Command);
        vector<string> Cmd = split(Command, " ");
        bool commandUsed = false;

        if (Cmd[0] == "echo") {
            commandUsed = true;
            string echo;

            for (int i = 1; i < Cmd.size(); i++) {
                if (i == 1) {
                    echo = Cmd[i];
                }
                else {
                    echo += " " + Cmd[i];
                }
            }

            cout << echo << endl;
        }

        if (Cmd[0] == "cd") {
            commandUsed = true;

            if (Cmd.size() > 1) {
                fs::path newPath = Cmd[1];

                if (!newPath.is_absolute()) {
                    newPath = fs::path(Path) / newPath;
                }

                try {
                    newPath = fs::canonical(newPath);
                }
                catch (fs::filesystem_error err) {
                    cout << "[ERR]: " << err.code() << endl;
                }

                if (fs::exists(newPath) && fs::is_directory(newPath)) {
                    fs::current_path(newPath);
                    strncpy_s(Path, newPath.string().c_str(), sizeof(Path) - 1);
                    Path[sizeof(Path) - 1] = '\0';
                    cout << "Changed directory to: " << Path << endl;
                }
                else {
                    cout << "Invalid path or directory does not exist." << endl;
                }
            }
            else {
                cout << "Current directory: " << Path << endl;
            }
        }

        if (Cmd[0] == "mkdir") {
        }

        if (!commandUsed) {
            cout << "Command " << Cmd[0] << " doesn't exist." << endl;
        }

        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    _fullpath(Path, argv[0], sizeof(Path));
    string strPath = "";
    strPath = strPath + Path;
    size_t pos = strPath.find("AutoShell.exe");
    if (pos != string::npos) {
        strPath = strPath.substr(0, pos);
    }
    strncpy_s(Path, strPath.c_str(), sizeof(Path));
    Path[sizeof(Path) - 1] = '\0';
    cout << "AutoShell v1.0.0\n\n";
    Loop();
}