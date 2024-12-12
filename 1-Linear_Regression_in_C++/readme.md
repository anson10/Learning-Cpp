# Linear Regression - Explanation

## What is Linear Regression?

Linear regression is a statistical method used to model the relationship between a dependent variable ($y$) and one or more independent variables ($x$). The goal of linear regression is to find the best-fitting line (also called a regression line) that predicts the value of $y$ based on the value of $x$. This model assumes a linear relationship between the variables, i.e., $y$ is a linear function of $x$.

### Simple Linear Regression

In the case of simple linear regression, the model assumes a linear relationship between a single independent variable $x$ and the dependent variable $y$. The equation of this relationship can be written as:

$$
y = mx + b
$$

Where:
- $y$: The predicted dependent variable (output).
- $x$: The independent variable (input).
- $m$: The slope of the line (weight).
- $b$: The y-intercept.

### Multiple Linear Regression

For multiple independent variables, the linear regression equation becomes:

$$
y = m_1x_1 + m_2x_2 + \cdots + m_nx_n + b
$$

Where:
- $x_1, x_2, \dots, x_n$: The independent variables.
- $m_1, m_2, \dots, m_n$: The weights corresponding to each independent variable.

## Cost Function

The cost function in linear regression is used to measure the difference between the predicted output and the actual output. It tells us how far off our predictions are from the true values. The most commonly used cost function is the **Mean Squared Error (MSE)**, which is given by:

$$
J(m, b) = \frac{1}{m} \sum_{i=1}^{m} \left( \hat{y}_i - y_i \right)^2
$$

Where:
- $J(m, b)$: The cost function.
- $m$: The number of training examples.
- $\hat{y}_i$: The predicted value for the $i$-th data point.
- $y_i$: The actual value for the $i$-th data point.

The goal of training a linear regression model is to minimize this cost function by adjusting the values of the parameters (weights) $m$ and $b$.

## Weights and Losses

The weights ($m$) and bias ($b$) in the linear regression model are learned during the training process. The model attempts to find the optimal values for $m$ and $b$ that minimize the cost function.

The **Loss** is the difference between the predicted value and the actual value. It can be defined for each data point as:

$$
\text{Loss}_i = \left( \hat{y}_i - y_i \right)^2
$$

The total loss is the sum of the losses for all data points:

$$
\text{Total Loss} = \sum_{i=1}^{m} \text{Loss}_i
$$

## Accuracy

Accuracy in linear regression is not defined in the same way as in classification problems. Since linear regression deals with continuous data, accuracy is usually not the best metric. Instead, we use **R-squared** or **Coefficient of Determination** to evaluate the performance of the model.

The R-squared value is given by:

$$
R^2 = 1 - \frac{\sum_{i=1}^{m} \left( \hat{y}_i - y_i \right)^2}{\sum_{i=1}^{m} \left( \bar{y} - y_i \right)^2}
$$

Where:
- $\hat{y}_i$: The predicted value for the $i$-th data point.
- $y_i$: The actual value for the $i$-th data point.
- $\bar{y}$: The mean of the actual values.

R-squared ranges from 0 to 1, with values closer to 1 indicating a better fit of the model to the data.

## Conclusion

Linear regression is a powerful and simple method used for predicting continuous values. By minimizing the cost function and optimizing the weights, we can build an accurate model for a given dataset. Understanding the concepts of cost function, weights, and losses helps in refining the model for better predictions.
