module ItemsHelper
	def getExtension(value)
		ext = ""
		value.reverse.split("").each do |i|
			if value[i]=="."
				break
			else
				ext = ext + value[i]
			end
		end
		return ext.reverse
	end
	def getFileName(value)
		max_length = 10
		pass_ext = false
		name = ""
		value.reverse.split("").each do |i|
			if value[i]=="/"
				break
			else
				name = name + value[i]
			end
		end
		name = name.reverse
		if name.length > max_length
			name = name[0,max_length] + "..."
		end
		return name
	end
	# def generate_hash(value) #NEEDS WORK STILL
	# 	randvalue = ((('a'..'z').to_a + ('0'..'9').to_a).shuffle)[0..4].join
	# 	if ensure_random(randvalue)==false
	# 		randvalue = ((('a'..'z').to_a + ('0'..'9').to_a).shuffle)[0..4].join
	# 	end
	# 	return randvalue;
	# end
	# def ensure_random(value)
	# 	@bubbles = Bubble.find(:all)
	# 	@bubbles.each do |bubble|
	# 		bubble.links.each do |link|
	# 			if link.link_hash == value
	# 				return false
	# 			end
	# 		end
	# 	end
	# 	return true
	# end
end
