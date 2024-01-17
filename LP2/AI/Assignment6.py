class EmployeePerformanceExpertSystem:
    def __init__(self):
        self.rules = {
            'communication_skill': {
                'low': 'Needs improvement in communication skills.',
                'medium': 'Communication skills are satisfactory.',
                'high': 'Excellent communication skills.'
            },
            'work_quality': {
                'low': 'Work quality is below expectations.',
                'medium': 'Meets expectations in work quality.',
                'high': 'Consistently delivers high-quality work.'
            },
            'initiative': {
                'low': 'Shows little initiative.',
                'medium': 'Demonstrates average initiative.',
                'high': 'Takes proactive initiative.'
            }
            # Add more performance criteria and their corresponding rules here
        }

    def evaluate_performance(self, employee_data):
        overall_performance = []
        for criterion, value in employee_data.items():
            if criterion in self.rules:
                performance_level = self.evaluate_criterion(criterion, value)
                overall_performance.append((criterion, performance_level))

        return overall_performance

    def evaluate_criterion(self, criterion, value):
        if criterion in self.rules:
            if value < 3:
                return 'low'
            elif 3 <= value <= 7:
                return 'medium'
            else:
                return 'high'
        else:
            return None

def main():
    expert_system = EmployeePerformanceExpertSystem()

    # Example employee data
    employee_data = {
        'communication_skill': 8,
        'work_quality': 5,
        'initiative': 2
        # Add more performance criteria and their values here
    }

    # Evaluate employee performance
    performance_result = expert_system.evaluate_performance(employee_data)

    # Print results
    print("Employee Performance Evaluation:")
    for criterion, level in performance_result:
        print(f"{criterion.capitalize()}: {expert_system.rules[criterion][level]}")

if __name__ == "__main__":
    main()
