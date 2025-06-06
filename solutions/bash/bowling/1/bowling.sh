#!/usr/bin/env bash

main() {
	throws=("$@")
	frame_totals=()

	# A frame might be one or two throws depending on if a strike was thrown,
	# so increment manually based on frame
	local -i frame_start=0

	# Keep track of last used throw to check for excess unscored throws at end
	local -i last_used_throw=0

	for throw in "${throws[@]}"; do
		if ((throw < 0)); then
			echo "Negative roll is invalid"
			return 1
		fi
		if ((throw > 10)); then
			echo "Pin count exceeds pins on the lane"
			return 1
		fi
	done

	for frame in {1..10}; do
		# Strike
		if ((throws[frame_start] == 10)); then

			# Validate that followed by two throws
			if ((frame_start + 2 >= ${#throws[@]})); then
				echo "Score cannot be taken until the end of the game"
				return 1
			fi

			# Validate two bonus throws are a valid frame or a strike and a bonus throw
			if ((throws[frame_start + 1] != 10)) && ((throws[frame_start + 1] + throws[frame_start + 2] > 10)); then
				echo "Pin count exceeds pins on the lane"
				return 1
			fi

			frame_totals[$frame]=$((10 + throws[frame_start + 1] + throws[frame_start + 2]))
			last_used_throw=$((frame_start + 2))
			frame_start+=1
			continue
		fi

		# If not a strike, ensure there are at least two throws and that the frame is valid
		if ((frame_start + 1 >= ${#throws[@]})); then
			echo "Score cannot be taken until the end of the game"
			return 1
		fi
		if ((throws[frame_start] + throws[frame_start + 1] > 10)); then
			echo "Pin count exceeds pins on the lane"
			return 1
		fi

		# Spare
		if ((throws[frame_start] + throws[frame_start + 1] == 10)); then

			# Validate that two throws of frame plus a bonus throw
			if ((frame_start + 2 >= ${#throws[@]})); then
				echo "Score cannot be taken until the end of the game"
				return 1
			fi

			frame_totals[$frame]=$((10 + throws[frame_start + 2]))
			last_used_throw=$((frame_start + 2))
			frame_start+=2
			continue
		fi

		# Open Frame
		frame_totals[$frame]=$(("${throws[$frame_start]}" + "${throws[frame_start + 1]}"))
		last_used_throw=$((frame_start + 1))
		frame_start+=2
	done

	# Check for illegal unscored throws
	if ((${#throws[@]} > last_used_throw + 1)); then
		echo "Cannot roll after game is over"
		return 1
	fi

	local -i score=0
	for total in "${frame_totals[@]}"; do
		((score += total))
	done

	echo "$score"
	return 0
}

main "$@"
