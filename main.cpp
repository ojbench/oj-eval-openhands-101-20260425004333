// Solution for ACMOJ 2866 - TOmorrow的指针
// Computes minimal positive seconds s until hour = minute = second in custom time system.
#include <iostream>
#include <algorithm>
#include <cstdint>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long a, b, c, d, e, f;
    if (!(std::cin >> a >> b >> c >> d >> e >> f)) return 0;

    const long long ab = a * b;
    const long long day = ab * c;
    const long long Tcur = f * ab + e * a + d;
    const long long limit = std::min({a, b, c});

    long long best = day; // strictly positive and < day
    for (long long x = 0; x < limit; ++x) {
        // Earliest time-of-day where hour = minute = second = x
        const long long base = x * (a + 1);
        const long long q = base / ab;            // floor(base / (ab))
        long long k0 = (x - q) % c;               // choose smallest nonnegative k0
        if (k0 < 0) k0 += c;
        const long long Tx = base + ab * k0;

        long long diff = (Tx - Tcur) % day;
        if (diff < 0) diff += day;
        if (diff == 0) diff = day;               // strictly later
        if (diff < best) best = diff;
    }

    std::cout << best << '\n';
    return 0;
}
