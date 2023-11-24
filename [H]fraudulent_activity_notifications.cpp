#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(vector<int> expenditure, int d) {
    int i, j, c = 0;
    float p;
    vector<int> m;
    m.push_back(expenditure[0]);
    for(i=1;i<expenditure.size();i++){
        if(i>=d){
            if(d%2 == 0){
                p = (float)(m[(d/2)-1]+m[d/2])/2;
            }else{
                p = m[d/2];
            }
            if(2*p <= expenditure[i]){
                c++;
            }
            int l = 0, h = d-1, mi;
            while(l<=h){
                mi = (l+h)/2;
                if(m[mi] == expenditure[i-d]){
                    break;
                }if(m[mi] < expenditure[i-d]){
                    l = mi+1;
                }else{
                    h = mi-1;
                }
            }
            m.erase(m.begin()+mi);
            // for(j=0;j<d;j++){
            //     if(expenditure[i-d] == m[j]){
            //         m.erase(m.begin()+j);
            //         break;
            //     }
            // }
            j = 0;
            l = 0;
            h = m.size()-1;
            while(l<=h){
                j = (l+h)/2;
                if(m[j] == expenditure[i]){
                    break;
                }if(l == h){
                    if(m[j] > expenditure[i]){
                        break;
                    }else{
                        j++;
                        break;
                    }
                }
                if(m[j] < expenditure[i]){
                    l = j+1;
                }else{
                    h = j-1;
                }
            }
            m.insert(m.begin()+j,expenditure[i]);
            printf("\n");
        }else{
            int l = 0;
            int h = m.size()-1;
            while(l<=h){
                j = (l+h)/2;
                if(m[j] == expenditure[i]){
                    break;
                }if(l == h){
                    if(m[j] > expenditure[i]){
                        break;
                    }else{
                        j++;
                        break;
                    }
                }
                if(m[j] < expenditure[i]){
                    l = j+1;
                }else{
                    h = j-1;
                }
            }
            m.insert(m.begin()+j,expenditure[i]);
        }
    }
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
