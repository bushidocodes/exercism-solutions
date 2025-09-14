#include <cassert>
#include <cmath>

constexpr int billable_days_per_month = 22;

// daily_rate calculates the daily rate given an hourly rate
[[nodiscard]] double daily_rate(double hourly_rate) noexcept {
    assert(hourly_rate > 0);
    return hourly_rate * 8;
}

// apply_discount calculates the price after a discount
[[nodiscard]] double apply_discount(double before_discount, double discount) noexcept {
    assert(before_discount > 0);
    assert(discount >= 0);
    assert(discount < 100);
    return before_discount * (1.0 - (discount / 100));
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
[[nodiscard]] int monthly_rate(double hourly_rate, double discount) noexcept {
    assert(hourly_rate > 0);
    assert(discount >= 0);
    assert(discount < 100);
    return std::ceil(apply_discount(daily_rate(hourly_rate) * billable_days_per_month, discount));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
[[nodiscard]] int days_in_budget(int budget, double hourly_rate, double discount) noexcept {
    assert(budget > 0);
    assert(hourly_rate > 0);
    assert(discount >= 0);
    assert(discount < 100);
    auto discounted_daily_cost = apply_discount(daily_rate(hourly_rate), discount);
    return std::floor(budget / discounted_daily_cost);
}
