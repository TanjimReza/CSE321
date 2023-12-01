class Test: 
    class_variable = "Global Value"
    
    def __init__(self):
        self.instance_variable = "Instance Value"
        

#! Default Class Variable
print(f"->Default Class Variable: {Test.class_variable}\n")
obj_1 = Test()
print(f"Obj_1 Class Variable: {obj_1.class_variable}\n")


print("-> Changing Class Variable Through Object-2")
obj_2 = Test()
obj_2.class_variable = "CHANGED"
print(f"Obj_2 Class Variable: {obj_2.class_variable}\n")

print(f"->Default Class Variable: {Test.class_variable}\n")
print("Default Class Variable is not changed because it is not changed through class name\n")



