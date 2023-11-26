#!/bin/bash

# Initialize variables
inputs=('"Hello, world!"' '"My name is $USER"' "'Single quotes'"
"'\$USER'" 
"\"\$USER\""
"\"'\$USER'\""
"'\"\$USER\"'"
)
bash_inputs=('echo "Hello, world!"' 'echo "My name is $USER"' "echo 'Single quotes'"
"echo '\$USER'" 
"echo \"\$USER\""
"echo \"'\$USER'\"
" "echo '\"\$USER\"'"
)

# Run commands in your shell and store their output
declare -a your_outputs
for input in "${inputs[@]}"; do
    output="$(./minishell << EOF
$input
exit
EOF
)"
    output=$(echo "$output" | tail -n +2)  # Skip the first line
    your_outputs+=("$output")
done

# Run the same commands in bash and store their output
declare -a bash_outputs
for bash_input in "${bash_inputs[@]}"; do
    output="$(bash -c "$bash_input")"
    bash_outputs+=("$output")
done

# Initialize count of matches
match_count=0

# Now compare the outputs
echo -e "\033[0;38m------------------------------------\033[0m"
for i in "${!inputs[@]}"; do
    echo -e "\033[0;37m${inputs[$i]}\033[0m"
    echo -e "\033[0;37mMine: \033[0m${your_outputs[$i]}"
    echo -e "\033[0;37mBash: \033[0m${bash_outputs[$i]}"
    if [ "${your_outputs[$i]}" == "${bash_outputs[$i]}" ]; then 
        echo -e "\033[0;32mOK\033[0m"
		((match_count++))
    else 
        echo -e "\033[0;31mKO\033[0m"
    fi
    echo -e "\033[0;38m------------------------------------\033[0m"
done

# Print summary
total_tests=${#inputs[@]}
if [ "${total_tests}" == "${match_count}" ]; then 
	echo -e "\033[0;32mPassed all tests! \033[0m"
	((match_count++))
else 
	echo -e "\033[0;31m$match_count/$total_tests\033[0m"
fi
