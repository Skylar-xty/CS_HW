import xlwt
import random

# 姓氏列表（这里是示例，你可以根据需要添加更多的姓氏）
surnames = ["王", "李", "张", "刘", "陈", "杨", "赵", "黄", "周", "吴", "徐", "孙"]

# 名字列表（这里是示例，你可以根据需要添加更多的名字）
names = [
    "米", "云", "乐", "子豪", "好", "静", "天天", "强", "博洋", "海鹏",
    "晨睿", "勇", "可爱", "杰", "西西", "涛", "明", "超", "子涵", "梓涵"
]
scores=[]
# 生成Excel文件
workbook = xlwt.Workbook()
sheet = workbook.add_sheet('学生信息')

# 写入表头
sheet.write(0, 0, '学生昵称')
sheet.write(0, 1, '真实姓名')
sheet.write(0, 2, '学号')
sheet.write(0, 3, '成绩')

# 用于存储已经生成的元素，确保不重复
generated_nicknames = set()
generated_names = set()
generated_ids = set()
generated_scores = set()
for i in range(1, 31):
    while True:
        # 随机选择姓氏和名字
        surname = random.choice(surnames)
        name = random.choice(names)
        full_name = surname + name

        if full_name not in generated_names:
            # 添加到集合中，表示已经生成过该姓名
            generated_names.add(full_name)
            break

    while True:
        # 生成学号
        student_id = f'20212{random.choice(["0", "1"])}{random.choice(["0", "1", "2"])}{str(random.randint(100, 999))}'

        if student_id not in generated_ids:
            # 添加到集合中，表示已经生成过该学号
            generated_ids.add(student_id)
            break


    # 生成成绩
    scores = random.randint(0,20)
        # generated_scores.add(scores)

    nickname = f'Student_{i}'
    if nickname not in generated_nicknames:
        # 添加到集合中，表示已经生成过该昵称
        generated_nicknames.add(nickname)
    else:
        # 如果昵称重复，增加一个后缀以确保唯一性
        counter = 1
        while f'{nickname}_{counter}' in generated_nicknames:
            counter += 1
        nickname = f'{nickname}_{counter}'
        generated_nicknames.add(nickname)

    # 将数据写入Excel文件
    sheet.write(i, 0, nickname)  # 学生昵称
    sheet.write(i, 1, full_name)  # 真实姓名
    sheet.write(i, 2, student_id)  # 学号
    sheet.write(i, 3, scores)
# 保存Excel文件
workbook.save('BB.xlsx')
