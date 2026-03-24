#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> m1, m2, sum1, pro1;

    int num1;
    cin >> num1;
    for (int i = 0; i < num1; i++)
    {
        int a, b;
        cin >> a >> b;
        m1[b] = a;
        sum1[b] = a;
    }
    int num2;
    cin >> num2;
    for (int i = 0; i < num2; i++)
    {
        int a, b;
        cin >> a >> b;
        m2[b] = a;
    }
    for (const auto &[key, value] : m2)
    {
        if (m1.count(key))
        {
            sum1[key] += value;
        }
        else
        {
            sum1[key] = value;
        }
    }
    
    for (auto i = m1.begin(); i != m1.end(); ++i)
    {
        for (auto j = m2.begin(); j != m2.end(); ++j)
        {
            int coeff, indice;
            indice = (i->first) + (j->first);
            coeff = (i->second) * (j->second);
            if(pro1.count(indice)){
                pro1[indice] += coeff;
            }
            else{
                pro1[indice] = coeff;
            }
            
        }
    }
    for (auto it = pro1.rbegin(); it != pro1.rend(); ++it)
    {
        cout << it->second << " " << it->first << " ";
    }
    cout << endl;
    for (auto it = sum1.rbegin(); it != sum1.rend(); ++it)
    {
        cout << it->second << " " << it->first << " ";
    }

    return 0;
}