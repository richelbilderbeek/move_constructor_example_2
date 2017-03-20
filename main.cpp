#include <array>
#include <cassert>
#include <utility>
#include <vector>

struct A{ std::array<int, 100> a; };
struct B{ int b; };
struct C{ int c; };
struct D{ int d; };
struct E{ int e; };

///const by reference initalization
class alpha
{
public:
  alpha(const std::vector<A>& as) : m_as{as} {}
  const std::vector<A> m_as;
};

///copy, no std::move
class beta
{
public:
  beta(std::vector<B> bs) : m_bs{bs} {}
  const std::vector<B> m_bs;
};

///copy, with std::move
class gamma
{
public:
  gamma(std::vector<C> cs) : m_cs{std::move(cs)} {}
  const std::vector<C> m_cs;
};

int main()
{
  const alpha a(std::vector<A>(100));
  const beta b(std::vector<B>(100));
  const gamma c(std::vector<C>(100));
}
