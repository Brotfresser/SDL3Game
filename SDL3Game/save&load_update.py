all_options_save_files = ["global_options.h"]
# just add to this array down below all files
all_game_save_files = []

out_file = "save_and_load.cpp"
global_define = "GLOBAL("

options_save_vars = []
option_start_load_mark = "// load option vars here begin"
option_end_load_mark = "// load option vars here end"
option_start_save_mark = "// save option vars here begin"
option_end_save_mark = "// save option vars here end"

game_save_vars = []
game_start_load_mark = "// load game vars here begin"
game_end_load_mark = "// load game vars here end"
game_start_save_mark = "// save game vars here begin"
game_end_save_mark = "// save game vars here end"


def load_vars(files_array: list, vars_array: list):
    out_array = []
    for file in files_array:
        print("|-loading vars from", file)
        file = open(file)
        for line in file:
            if "namespace" in line:
                namespace = line.split()[1]
                break
        else:
            print("ERROR: not find namespace")
            continue

        for line in file:
            while global_define in line:
                start_id = line.find(global_define) + len(global_define)
                var = line[start_id:line.find(");")]
                var = var.split(',')[1].strip()
                vars_array.append({"namespace": namespace, "var": var})
                try:
                    line = line[line.find(");")+3:]
                except IndexError:
                    break
        file.close()


def save_vars(vars_array: list, start_load_mark: str, end_load_mark: str, start_save_mark: str, end_save_mark: str):
    print("saving vars in", out_file)
    file = open(out_file).readlines()

    start_load_id = end_load_id = start_save_id = end_save_id = -1
    for i in range(len(file)):
        if start_load_mark in file[i]:
            start_load_id = i
        elif end_load_mark in file[i]:
            end_load_id = i
        elif start_save_mark in file[i]:
            start_save_id = i
        elif end_save_mark in file[i]:
            end_save_id = i
    print(f"|-{start_load_mark} in line: {start_load_id+1}")
    print(f"|-{end_load_mark} in line: {end_load_id+1}")
    print(f"|-{start_save_mark} in line: {start_save_id+1}")
    print(f"|-{start_save_mark} in line: {end_save_id+1}")
    for var in [start_load_id, end_load_id, start_save_id, end_save_id]:
        if var == -1:
            print(f"CRITICAL ERROR: not find {var} in {out_file}")
            exit()
    if (start_load_id > end_load_id) or (start_save_id > end_save_id):
        print(f"CRITICAL ERROR: {start_load_id} {end_load_id} {start_save_id} {end_save_id} {out_file}")
        print("\tWRONG ORDER OF MARKS")
        exit()

    print("updating load_func")
    for i, line_id in enumerate(range(start_load_id + 1, start_load_id + len(vars_array) + 1)):
        msg = vars_array[i]
        namespace = msg["namespace"]
        var = msg["var"]
        string = f'\t{namespace}::{var} = load_json["{var}"];\n'
        if (line_id >= end_load_id):
            file.insert(line_id, string)
        else:
            file[line_id] = string

    # id may change, 'cause we maybe file.insert some vars instead of file[line_id]
    mod = start_load_id + len(vars_array) - end_load_id + 1
    start_save_id += mod
    end_save_id += mod
    print("updating save_func")
    for i, line_id in enumerate(range(start_save_id + 1, start_save_id + len(vars_array) + 1)):
        msg = vars_array[i]
        namespace = msg["namespace"]
        var = msg["var"]
        string = f'\tsave_json["{var}"] = {namespace}::{var};\n'
        if (line_id >= end_save_id):
            file.insert(line_id, string)
        else:
            file[line_id] = string

    with open(out_file, 'w') as write_file:
        write_file.writelines(file)


print("start updating script for", out_file)
load_vars(all_options_save_files, options_save_vars)
save_vars(options_save_vars, option_start_load_mark, option_end_load_mark, option_start_save_mark, option_end_save_mark)