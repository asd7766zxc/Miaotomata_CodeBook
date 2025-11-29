// 0 <= x < p, s.t. x^2 mod p = n 
// if not exist -> return -1
i32 SqrtMod(i32 n, i32 P) {
    if (P == 2 or n == 0) return n;
    if (power(n, (P - 1) / 2, P) != 1) return -1;
    mt19937 rng(12312);
    i64 z = 0, w;
    while (power(w = (z * z - n + P) % P, (P - 1) / 2, P) != P - 1)
        z = rng() % P;
    const auto M = [P, w](auto &u, auto &v) {
        return pair{
            (u.first * v.first + u.second * v.second % P * w) % P,
            (u.first * v.second + u.second * v.first) % P
        };
    };
    pair<i64, i64> r{1, 0}, e{z, 1};
    for (i32 w = (P + 1) / 2; w; w >>= 1, e = M(e, e))
        if (w & 1) r = M(r, e);
    return r.first; // second one is (mod - r.first)
}