# @param {String} instructions
# @return {Boolean}

def is_robot_bounded(instructions)
  directions = %w[N E S W]
  # Corresponds to N, E, S, W resp
  current_coordinates = [0, 0, 0, 0]
  current_direction = 0

  instructions.chars.each do |instruction|
    case instruction
    when 'G'
      current_coordinates[current_direction] += 1
    when 'L'
      if current_direction == 0
        current_direction = 3
      else
        current_direction -= 1
      end
    when 'R'
      if current_direction == 3
        current_direction = 0
      else
        current_direction += 1
      end
    end
  end

  result_coordinates = [
    current_coordinates[0] - current_coordinates[2],
    current_coordinates[1] - current_coordinates[3]
  ]

  result_coordinates == [0, 0] || current_direction != 0
end

