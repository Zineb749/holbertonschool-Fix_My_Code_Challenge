###
#
#  Sort integer arguments (ascending) 
#
###

result = []
ARGV.each do |arg|
    # skip if not integer
    next if arg !~ /^-?[0-9]+$/

    i_arg = arg.to_i

    # insert result at the right position
    is_inserted = false
    i = 0
    l = result.size
    while !is_inserted && i < l
        if result[i] > i_arg
            result.insert(i, i_arg)
            is_inserted = true
        else
            i += 1
        end
    end

    result << i_arg if !is_inserted
end

puts result
