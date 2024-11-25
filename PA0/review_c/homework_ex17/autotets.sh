#!/bin/bash
compile_if_needed(){
    if [ Makefile -nt ex17 ] || [ $(find . -name '*.c' -newer ex17 | wc -l) -gt 0 ]; then
        echo "Recompiling.."
        make auto || { echo "Compilation failed. Exiting with 1"; exit 1; }
    fi
}

ex17_data_file="db.dat"
ex17_id="1"
ex17_name="gaoxiang"
ex17_email="2627403974@qq.com"
run_test_set(){
    ./ex17 "$ex17_data_file" s "$ex17_id" "$ex17_name" "$ex17_email" #prevent the excutable file ex17 think $ex17_name is two args if ex17_name="gao xiang", please notice the blank space
}
run_test_get(){
    ./ex17 "$ex17_data_file" g "$ex17_id"
}
run_test_delete(){
    ./ex17 "$ex17_data_file" d "$ex17_id"
}
run_test_list(){
    ./ex17 "$ex17_data_file" l
}
run_test_set_get(){
    run_test_set
    run_test_get
}
run_test_delete_get(){
    run_test_delete
    run_test_get
}

# main
compile_if_needed
PS3="Please input an option:"
select test_opt in test_set test_get test_delete test_list test_set_get test_delete_get exit; do
    case $test_opt in
    test_set)       run_test_set;;
    test_get)       run_test_get;;
    test_delete)    run_test_delete;; 
    test_list)      run_test_list;;   
    test_set_get)   run_test_set_get;;
    test_delete_get)run_test_delete_get;;
    exit)           break;;            
    esac
done