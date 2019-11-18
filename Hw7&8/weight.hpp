//
// Created by Brady Bodily on 11/17/19.
//
#ifndef HW7_8_WEIGHT_HPP
#define HW7_8_WEIGHT_HPP
#include <ratio>
namespace usu
{
    template <typename T, typename T2 = std::uint64_t>
    class weight
    {
      private:
        T2 valCount;

      public:
        using ratio = T;
        weight() :
            valCount(0){};
        weight(T2 count) :
            valCount(count){};
        T2 count() { return valCount; };
    };

    template <typename T, typename T2>
    T weight_cast(T2 input)
    {
        return T(static_cast<double>((T::ratio::den * T2::ratio::num) * input.count()) / (T::ratio::num * T2::ratio::den));
    }

    template <typename T>
    T operator*(double scalar, T weight)
    {
        auto count = weight.count();
        auto newCount = static_cast<decltype(count)>(scalar * count);
        T newweight(newCount);
        return newweight;
    }

    template <typename T>
    T operator*(T weight, double scalar)
    {
        return scalar * weight;
    }

    template <typename T, typename T2>
    T operator+(T l, T2 r)
    {
        T returnWeight(l.count() + r.count());
        return returnWeight;
    }

    template <typename T, typename T2>
    T operator-(T l, T2 r)
    {
        T returnWeight(l.count() - r.count());
        return returnWeight;
    }

    //america
    using ounce = weight<std::ratio<35'273'961, 1'000'000'000>>;
    using pound = weight<std::ratio<2'204'622, 1'000'000'000>>;
    using ton = weight<std::ratio<1'102'311, 1'000'000'000'000>>;
    //metrics
    using microgram = weight<std::ratio<1, 1'000'000>>;
    using gram = weight<std::ratio<1, 1>>;
    using kilogram = weight<std::ratio<1'000, 1>>;

}
#endif // HW7_8_WEIGHT_HPP
