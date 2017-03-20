#include <array>
#include <cassert>
#include <utility>
#include <vector>

struct A{ int a; };
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
  for (int i=0; i!=1000; ++i)
  {
    const alpha a(std::vector<A>(1'000'000));
    const beta b(std::vector<B>(1'000'000));
    const gamma c(std::vector<C>(1'000'000));
    assert(a.m_as.size() == b.m_bs.size());
    assert(b.m_bs.size() == c.m_cs.size());
  }
}
