def make_dec(t, st_number):
    nlen = len(st_number)
    ttimes = 1
    ret = 0
    for i in range(nlen-1, -1, -1):
        ret += int(st_number[i], 10) * ttimes
        ttimes *= t
    return ret

def make_dec2t(t, number):
    if number == 0:
        return '0'
    ret = ''
    while(number) :
        ret += str(number % t)
        number //= t
    ret = list(ret)
    ret.reverse()
    ret = ''.join(ret)
    return ret

def solution(expressions):
    answer = []
    problem_exp = []
    candidate = [1 for _ in range(11)]
    for expression in expressions:
        exp = expression.split()
        number1 = exp[0]
        number2 = exp[2]
        number3 = exp[4]
        oper = exp[1]
        
        if number3 == 'X':
            problem_exp.append(expression)
            mxt = 1
            numbers = number1+number2
            for k in numbers:
                if int(k, 10) > mxt:
                    mxt = int(k, 10)

            mxt += 1
            for i in range(0, mxt) : candidate[i] = 0
            continue
        
        mxt = 1
        numbers = number1+number2+number3
        for k in numbers:
            if int(k, 10) > mxt:
                mxt = int(k, 10)
                
        mxt += 1
        for i in range(0, mxt) : candidate[i] = 0
    
            
        for t in range(mxt, 11):
            num1_dec = make_dec(t, number1)
            num2_dec = make_dec(t, number2)
            num3_dec = make_dec(t, number3)
            
            
            if oper == '+' and num1_dec + num2_dec != num3_dec :
                candidate[t] = 0
            if oper == '-' and num1_dec - num2_dec != num3_dec :
                candidate[t] = 0
        
    
    if sum(candidate) == 1:
        anst = 0
        for i in range(2, 10):
            if candidate[i] == 1:
                anst = i
                break
        for pexp in problem_exp:
            pexps = pexp.split()
            num1 = pexps[0]
            num2 = pexps[2]
        
            op = pexps[1]
            
            num1_dec = make_dec(anst, num1)
            num2_dec = make_dec(anst, num2)
            ansk = num1_dec+num2_dec if op == '+' else num1_dec - num2_dec
            
            num3 = make_dec2t(anst, ansk)
            answer.append(f"{num1} {op} {num2} = {num3}")   
    else :
        
        curr_exp = ''
        for pexp in problem_exp:
            curr_ans = ''
            curr_exp = pexp
            flag = False
            for t in range(2, 10):
                if candidate[t] == 0 : continue
                
                pexps = pexp.split()
                num1 = pexps[0]
                num2 = pexps[2]

                op = pexps[1]

                num1_dec = make_dec(t, num1)
                num2_dec = make_dec(t, num2)
                ansk = num1_dec+num2_dec if op == '+' else num1_dec - num2_dec
                
                num3 = make_dec2t(t, ansk)
                
                if curr_ans == '':
                    curr_ans = num3
                elif curr_ans != num3:
                    flag = True
                    answer.append(f"{num1} {op} {num2} = ?")
                    break
            
            if flag is False:
                answer.append(curr_exp[:-1] + curr_ans)
        
        
        
    return answer