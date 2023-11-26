#!/bin/bash

# Initialize variables
input1='"Hello, world!"'
input1_bash='echo "Hello, world!"'
input2='"My name is $USER"'
input2_bash='echo "My name is $USER"'

# Run commands in your shell and store their output
your_output1="$(./minishell << EOF
$input1
exit
EOF
)"
your_output2="$(./minishell << EOF
$input2
exit
EOF
)"

# Run the same commands in bash and store their output
bash_output1="$(bash -c "$input1_bash")"
bash_output2="$(bash -c "$input2_bash")"

# Now compare the outputs
echo -e "Command: $input1"
echo -e "Minshell:
$your_output1" | grep -v '^minishell\$'
echo -e "Bash:
$bash_output1"
if [ "$your_output1" == "$bash_output1" ]; then 
    echo -e "\033[0;32mOK\033[0m"
else 
    echo -e "\033[0;31mKO\033[0m"
fi

echo -e "
Command: $input2"
echo -e "Minishell:
$your_output2" | grep -v '^minishell\$'
echo -e "Bash:
$bash_output2"
if [ "$your_output2" == "$bash_output2" ]; then 
    echo -e "\033[0;32mOK\033[0m"
else 
    echo -e "\033[0;31mKO\033[0m"
fi