SELECT CART_ID
FROM CART_PRODUCTS
Where Name = "Yogurt" or Name = "Milk"
GROUP BY CART_ID
Having COUNT(DisTinct name)>=2