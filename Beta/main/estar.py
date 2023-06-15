# Open the file in write mode
file_path = "main/ok.txt"
with open(file_path, 'w') as file:
    # Write some text to the file
    for i in range(1, 1001):
        file.write(f'{0.001 * i}\n')

# The file is automatically closed once the `with` block is exited
