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
end