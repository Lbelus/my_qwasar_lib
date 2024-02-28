fn main()
{
    {
        let my_nested_variable = 30;
        println!("30 -> {}", my_nested_variable);
        // end for my_nested_variable    
    }
    {
        let my_nested_variable = 1;
        println!("1 -> {}", my_nested_variable);
        // end for my_nested_variable    
    }
    {
        let my_nested_variable = 30;
        let my_nested_variable_2 = 1;
        println!("30 && 1 -> {} - {}", my_nested_variable_2, my_nested_variable);
        // end for my_nested_variable and my_nested_variable_2
    }
    {
        let my_nested_variable = 1_000;
        let my_nested_variable_2 = -1;
        println!("1_000 && -1 -> {} - {}", my_nested_variable, my_nested_variable_2);
        // end for my_nested_variable and my_nested_variable_2
    }
}