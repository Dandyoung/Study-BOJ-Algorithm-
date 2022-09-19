#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream fin("snail.inp");
    ofstream fout("snail.out");
    vector <long long> v;
    vector <long long> zz;
    long long layer;
    fin >> layer;
    long long cnt = 0;

    while (cnt < layer) {
        long long n, p1, p2;
        fin >> n >> p1 >> p2;

        long long start = 1;
        long long end = 4 * n - 4;
        long long qqq = 1;

        for (double i = 0; i < ceil(n / 2); i++) {
            if (start <= p1 && p1 <= end) {
                break;
            }
            else {
                qqq += 1;
                start = end + 1;
                end += (4 * n) - (8 * qqq) + 4;
            }
        }

        long long x, y;
        x = qqq;
        y = qqq;

        long long rng = n - 2 * (qqq - 1);

        if (start <= p1 && p1 <= start + (rng - 1)) {
            long long a = p1 - start;
            y += a;
        }

        else if (start + (rng - 1) <= p1 && p1 <= start + (rng - 1) + (rng - 1)) {
            if (start + (rng - 1) != p1) {
                y += rng - 1;
                long long b = p1 - (start + (rng - 1));
                x += b;
            }
        }

        else if (start + (rng - 1) + (rng - 1) <= p1 && p1 <= start + (rng - 1) + (rng - 1) + (rng - 1)) {
            if (start + (rng - 1) + (rng - 1) != p1) {
                x += rng - 1;
                long long c = (start + (rng - 1) + (rng - 1) + (rng - 1)) - p1;
                y += c;
            }
        }
        else if (start + (rng - 1) + (rng - 1) + (rng - 1) <= p1 && p1 <= start + (rng - 1) + (rng - 1) + (rng - 1) + (rng - 2)) {
            if (start + (rng - 1) + (rng - 1) + (rng - 1) != p1) {
                if (p1 == start + (rng - 1) + (rng - 1) + (rng - 1) + (rng - 2)) {
                    x += 1;
                }
                else {
                    long long d = (start + (rng - 1) + (rng - 1) + (rng - 1) + (rng - 2)) - p1 + 1;
                    x += d;
                }
            }
        }


        long long start2 = 1;
        long long end2 = 4 * n - 4;
        long long qqq2 = 1;

        for (double i = 0; i < ceil(n / 2); i++) {
            if (start2 <= p2 && p2 <= end2) {
                break;
            }
            else {
                qqq2 += 1;
                start2 = end2 + 1;
                end2 += (4 * n) - (8 * qqq2) + 4;
            }
        }
        long long t = qqq2;
        long long f = qqq2;
        long long rng2 = n - 2 * (qqq2 - 1);
        if (start2 <= p2 && p2 <= start2 + (rng2 - 1)) {
            long long a2 = p2 - start2;
            f += a2;
        }

        else if (start2 + (rng2 - 1) <= p2 && p2 <= start2 + (rng2 - 1) + (rng2 - 1)) {
            if (start2 + (rng2 - 1) != p2) {
                f += rng2 - 1;
                long long b2 = p2 - (start2 + (rng2 - 1));
                t += b2;
            }
        }

        else if (start2 + (rng2 - 1) + (rng2 - 1) <= p2 && p2 <= start2 + (rng2 - 1) + (rng2 - 1) + (rng2 - 1)) {
            if (start2 + (rng2 - 1) + (rng2 - 1) != p2) {
                t += rng2 - 1;
                long long c2 = (start2 + (rng2 - 1) + (rng2 - 1) + (rng2 - 1)) - p2;
                f += c2;
            }
        }
        else if (start2 + (rng2 - 1) + (rng2 - 1) + (rng2 - 1) <= p2 && p2 <= start2 + (rng2 - 1) + (rng2 - 1) + (rng2 - 1) + (rng2 - 2)) {
            if (start2 + (rng2 - 1) + (rng2 - 1) + (rng2 - 1) != p2) {
                if (p2 == start2 + (rng2 - 1) + (rng2 - 1) + (rng2 - 1) + (rng2 - 2)) {
                    t += 1;
                }
                else {
                    long long d2 = (start2 + (rng2 - 1) + (rng2 - 1) + (rng2 - 1) + (rng2 - 2)) - p2 +1;
                    t += d2;
                }
            }
        }
        cnt++;

        if (abs(x - t) == abs(y - f)) {
            fout << "YES" << '\n';
        }
        else {
            fout << "NO" << '\n';
        }
    }
    fin.close();
    fout.close();
}
