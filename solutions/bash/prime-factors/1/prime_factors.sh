#!/usr/bin/env bash

main() {
	local -i input="$1"
	local -i prime_idx=0
	local -a prime_factors=()
	local prime

	# Load memoized primes if available
	declare -a primes=(2 3)
	if [[ ! -e ./primes.txt ]]; then
		for i in "${primes[@]}"; do
			echo "$i" >> ./primes.txt
		done
	fi
	readarray -t primes < ./primes.txt

	while ((input > 1)); do

		# Check known primes for factors
		for (( ; prime_idx < ${#primes[@]}; prime_idx++)); do
			((input <= 1)) && break 2
			prime=${primes[$prime_idx]}
			while ((input % prime == 0)); do
				((input /= prime))
				prime_factors+=("$prime")
			done
		done

		((input == 1)) && break

		# Calculate additional primes if known primes are exhausted
		local last_known_prime="${primes[-1]}"

		# Expand to the lesster of double last known prime or input
		local -i goal
		if ((input < last_known_prime * 2)); then
			goal=$input
		else
			goal=$((last_known_prime * 2))
		fi

		# Use Sieve of Eratosthenes to find primes
		local -a is_prime
		for ((i = last_known_prime + 2; i <= goal; i += 2)); do
			is_prime[$i]=true
		done

		for prime in "${primes[@]}"; do
			((prime == 2)) && continue
			for ((i = prime; i <= goal; i += prime)); do
				((i < last_known_prime)) && continue
				is_prime[$i]=false
			done
		done

		for ((i = last_known_prime + 2; i <= goal; i += 2)); do
			if [[ ${is_prime[$i]} == true ]]; then
				primes+=("$i")
				echo "$i" >> primes.txt
			fi
		done

		if ((input == goal)) && [[ ${is_prime[$goal]} == true ]]; then
			prime_factors+=("$input")
			input=1
			break
		fi
	done

	echo "${prime_factors[*]}"
	return 0
}

main "$@"
