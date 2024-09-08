from flask import Flask, request, jsonify
import pickle
import numpy as np
import os

app = Flask(__name__)
folder_path = r'C:\Users\WIIS'  # Use raw string to avoid backslash issues
file_name1 = 'model_nitrogen.pkl'
file_name2 = 'scaler.pkl'
file_name3 = 'model_phosphorus.pkl'
file_name4 = 'model_potassium.pkl'

# Function to load pickle file and handle errors
def load_pickle_file(file_path):
    try:
        with open(file_path, 'rb') as f:
            return pickle.load(f)
    except Exception as e:
        print(f"Error loading file {file_path}: {str(e)}")
        return None

# Load the pre-trained models and scaler
model_nitrogen = load_pickle_file(os.path.join(folder_path, file_name1))
model_phosphorus = load_pickle_file(os.path.join(folder_path, file_name3))
model_potassium = load_pickle_file(os.path.join(folder_path, file_name4))
scaler = load_pickle_file(os.path.join(folder_path, file_name2))

@app.route('/')
def home():
    return "Nutrient Prediction API"

@app.route('/predict', methods=['POST'])
def predict():
    try:
        # Ensure models and scaler are loaded
        if not all([model_nitrogen, model_phosphorus, model_potassium, scaler]):
            return jsonify({'error': 'Failed to load one or more models or the scaler.'}), 500

        # Extract the input data from the request
        data = request.json
        soil_moisture = data['Soil Moisture']
        rainfall = data['Rainfall']
        humidity = data['Humidity']
        temperature = data['Temperature']
        growth_stage = data['Growth Stage']

        # Prepare the input features for prediction
        input_data = np.array([[soil_moisture, rainfall, humidity, temperature, growth_stage]])
        input_scaled = scaler.transform(input_data)

        # Predict using the trained models
        predicted_nitrogen = model_nitrogen.predict(input_scaled)[0]
        predicted_phosphorus = model_phosphorus.predict(input_scaled)[0]
        predicted_potassium = model_potassium.predict(input_scaled)[0]

        # Prepare the response
        response = {
            'Predicted Nitrogen': f"{predicted_nitrogen:.2f} grams/m²",
            'Predicted Phosphorus': f"{predicted_phosphorus:.2f} grams/m²",
            'Predicted Potassium': f"{predicted_potassium:.2f} grams/m²"
        }

        return jsonify(response)
    except Exception as e:
        return jsonify({'error': str(e)})

if __name__ == '__main__':
    app.run(debug=True)
