from flask import *

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/submit', methods=['POST'])
def submit():
    name = request.form['name']
    email = request.form['email']
    age = request.form['age']

    return f'''
    <html>
      <head>
        <title>Flask Example</title>
      </head>
      <body>
        <h2>Flask Example</h2>
        <p>Name: {name}</p>
        <p>Email: {email}</p>
        <p>Age: {age}</p>
      </body>
    </html>
    '''

if __name__ == '__main__':
    app.run(debug=True)
