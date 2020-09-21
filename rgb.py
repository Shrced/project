from PIL import Image, ImageDraw
image = Image.open('test.jpg')
draw = ImageDraw.Draw(image)
width = image.size[0]
height = image.size[1]
pix = image.load()
for x in range(width):
    for y in range(height):
       r = pix[x, y][0]
       g = pix[x, y][1]
       b = pix[x, y][2]
       sr = (r + g + b) // 3
       draw.point((x, y), (sr, sr, sr))

image.save("result.jpg", "JPEG")