// Returns g = gcd(a, b), and finds one pair (x, y) such that:
//     a * x + b * y = g
i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y = (i64)((i128)y - (i128)(a / b) * x);
    return g;
}
// Solves the linear congruence:
//     a * x = b (mod m)
// Let g = gcd(a, m).
// Returns one canonical solution x in [0, m / g).
// Returns -1 if no solution exists.
i64 inverse(i64 a, i64 b, i64 m) {
    i64 g = gcd(a, m);
    if (b % g != 0) return -1;

    i64 reduced_a = a / g;
    i64 reduced_b = b / g;
    i64 reduced_m = m / g;

    i64 x, y;
    exgcd(reduced_a, reduced_m, x, y);

    i64 ans = (i64)((i128)x * reduced_b % reduced_m);
    if (ans < 0) ans += reduced_m;
    return ans;
}