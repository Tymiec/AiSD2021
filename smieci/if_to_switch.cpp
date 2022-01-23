for (unsigned int i = 0 ; i < input.size(); i++)
    {
        if (isnumber(input[i]))
        {
            x = stod(input[i]);
            push(array,iterator,x);
        }
        else
        switch (input[i])
        {
        case '+':
        x = pop(array,iterator);
        y = pop(array,iterator);
        z = x + y;
        push(array,iterator,z);
        break;

        case '-':
        x = pop(array,iterator);
        y = pop(array,iterator);
        z = y - x;
        push (array,iterator,z);       
        break;

        case '*':
        x = pop(array,iterator);
        y = pop(array,iterator);
        z = x*y;
        push(array,iterator,z);        
        break;

        case '/':
        x = pop(array,iterator);
        y = pop(array,iterator);
        assert(x!=0);)
        z = y / x;
        push(array,iterator,z);
        break;
        
        default:
            break;
        }
    }
       

for (unsigned int i = 0 ; i < input.size(); i++)
   {
      switch (input[i])
      {
        case '+':
        x = pop(array,iterator);
        y = pop(array,iterator);
        z = x + y;
        push(array,iterator,z);

        case '-':
        x = pop(array,iterator);
        y = pop(array,iterator);
        z = y - x;
        push (array,iterator,z);

        case '*':
        x = pop(array,iterator);
        y = pop(array,iterator);
        z = x*y;
        push(array,iterator,z);

        case '/':
        x = pop(array,iterator);
        y = pop(array,iterator);
        assert(x!=0);)
        z = y / x;
        push(array,iterator,z);
         
        default:
        break;
      }
   }